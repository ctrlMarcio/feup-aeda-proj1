#include <fstream>
#include <vector>
#include "../../application/io/file_handling.h"
#include "../../exception/invalid_file_exception.h"
#include "../../util/string_util.h"
#include "client_company_manager.h"

using namespace std;

ClientCompany ClientCompanyManager::build(string name, string identification_number, string address) {
	return ClientCompany(std::move(name), std::move(identification_number), std::move(address));
}

bool ClientCompanyManager::add(ClientCompany &client) {
	if (has(client) || has(client.getIdentificationNumber())) return false;
	clients.push_back(client);
	return true;
}

bool ClientCompanyManager::remove(ClientCompany &client) {
	if (!has(client) || !has(client.getIdentificationNumber())) return false;
	clients.erase(find(clients.begin(), clients.end(), client));
	return true;
}

bool ClientCompanyManager::has(ClientCompany &client) const {
	return find(clients.begin(), clients.end(), client) != clients.end();
}

bool ClientCompanyManager::has(const string &identification_number) const {
	return find_if(clients.begin(), clients.end(), [&identification_number](const ClientCompany &client) {
		return client.getIdentificationNumber() == identification_number;
	}) != clients.end();
}

ClientCompany *ClientCompanyManager::get(const string &identification_number) {
	auto it = clients.begin();

	while (it != clients.end()) {
		if ((*it).getIdentificationNumber() == identification_number) {
			return &(*it);
		}
		it++;
	}

	return nullptr;
}

void ClientCompanyManager::read(const std::string &directory) {
	std::string file_path = directory + "/" + file_handling::client_company;

	ifstream ifstream;
	ifstream.open(file_path);

	if (!ifstream.is_open()) {
		std::cout << file_path << " not found! Creating an empty one." << endl;
		std::ofstream file{file_path};
		ifstream.open(file_path);
	}

	std::string line;
	while (getline(ifstream, line)) {
		line = string_util::removeCarriageReturn(line);

		std::vector<std::string> params = string_util::split(line, file_handling::delimiter);
		std::string name = params[0];
		std::string identification_number = params[1];
		std::string address = params[2];

		auto *client_company = new ClientCompany(name, identification_number, address);

		for (unsigned i = 3; i < params.size(); ++i) {
			std::string type = params[i];
			if (type == "passenger_pref") {
				unsigned min_year = stoul(params[++i]);
				unsigned seat_number = stoul(params[++i]);

				client_company->getPreferenceList().updatePreference(min_year, seat_number);
			} else if (type == "commercial_pref") {
				unsigned min_year = stoul(params[++i]);
				float cargo_volume = stof(params[++i]);
				float min_max_weight = stof(params[++i]);
				++i;
				bool refrigerated = params[i] == "y" || params[i] == "yes" || params[i] == "1" || params[i] == "t" || params[i] == "true";

				client_company->getPreferenceList().updatePreference(min_year, cargo_volume, min_max_weight, refrigerated);
			} else {
				break;
			}
		}

		this->add(*client_company);
	}

	ifstream.close();
}

void ClientCompanyManager::write(const std::string &directory) const {
	std::string file_path = directory + "/" + file_handling::client_company;

	ofstream ofstream;
	ofstream.open(file_path);

	if (!ofstream.is_open())
		throw InvalidFileException(file_path);

	for (const ClientCompany &client : clients) {
		ofstream << client.getName() << file_handling::delimiter
				 << client.getIdentificationNumber() << file_handling::delimiter
				 << client.getAddress();

		if (client.getPreferenceList().getPassengerPreference() != nullptr)
			ofstream << file_handling::delimiter << "passenger_pref" << file_handling::delimiter
					 << client.getPreferenceList().getPassengerPreference()->getMinYear() << file_handling::delimiter
					 << client.getPreferenceList().getPassengerPreference()->getSeatNumber();

		if (client.getPreferenceList().getCommercialPreference() != nullptr) {
			ofstream << file_handling::delimiter << "commercial_pref" << file_handling::delimiter
					 << client.getPreferenceList().getCommercialPreference()->getMinYear() << file_handling::delimiter
					 << client.getPreferenceList().getCommercialPreference()->getCargoVolume() << file_handling::delimiter
					 << client.getPreferenceList().getCommercialPreference()->getMinMaxWeight() << file_handling::delimiter;

			if (client.getPreferenceList().getCommercialPreference()->isRefrigerated())
				ofstream << "true";
			else ofstream << "false";
		}

		ofstream << std::endl;
	}

	ofstream.close();
}
