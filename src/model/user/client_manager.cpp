#include "client_manager.h"

#include <utility>
#include <fstream>
#include "../../application/io/file_handling.h"
#include "../../exception/invalid_file_exception.h"
#include "../../util/string_util.h"
#include "../contract/contract_manager.h"

Client ClientManager::build(string name, string identification_number, string address) {
	return Client(std::move(name), std::move(identification_number), std::move(address));
}

bool ClientManager::add(Client &client) {
	if (has(client) || has(client.getIdentificationNumber())) return false;
	clients.push_back(client);
	return true;
}

bool ClientManager::remove(Client &client) {
	if (!has(client) || !has(client.getIdentificationNumber())) return false;
	clients.erase(find(clients.begin(), clients.end(), client));
	return true;
}

bool ClientManager::has(Client &client) const {
	return find(clients.begin(), clients.end(), client) != clients.end();
}

bool ClientManager::has(const string &identification_number) const {
	return find_if(clients.begin(), clients.end(), [&identification_number](const Client &client) {
		return client.getIdentificationNumber() == identification_number;
	}) != clients.end();
}

Client *ClientManager::get(const string &identification_number) {
	auto it = clients.begin();

	while (it != clients.end()) {
		if ((*it).getIdentificationNumber() == identification_number) {
			return &(*it);
		}
		it++;
	}

	return nullptr;
}

void ClientManager::read(const std::string &directory) {
	std::string file_path = directory + "/" + file_handling::client;

	ifstream ifstream;
	ifstream.open(file_path);

	if (!ifstream.is_open())
		throw InvalidFileException(file_path);

	std::string line;
	while (getline(ifstream, line)) {
		std::vector<std::string> params = string_util::split(line, file_handling::delimiter);
		std::string name = params[0];
		std::string identification_number = params[1];
		std::string address = params[2];

		auto *client = new Client(name, identification_number, address);

		size_t i = 3;
		if (params.size() > i && params[i] == "passenger_pref")
			i = readPassengerPreference(params, client, i);

		if (params.size() > i && params[i] == "commercial_pref")
			i = readCommercialPreference(params, client, i);

		client->getVehicleList().read(params, i);
		this->add(*client);
	}

	ifstream.close();
}

size_t ClientManager::readCommercialPreference(const vector<std::string> &params, Client *client, size_t i) const {
	unsigned min_year = stoul(params[++i]);
	float cargo_volume = stof(params[++i]);
	float min_max_weight = stof(params[++i]);
	++i;
	bool refrigerated =
			params[i] == "y" || params[i] == "yes" || params[i] == "1" || params[i] == "t" || params[i] == "true";
	++i;
	client->getPreferenceList().updatePreference(min_year, cargo_volume, min_max_weight, refrigerated);
	return i;
}

size_t ClientManager::readPassengerPreference(const vector<std::string> &params, Client *client, size_t i) const {
	unsigned min_year = stoul(params[++i]);
	unsigned seat_number = stoul(params[++i]);
	++i;

	client->getPreferenceList().updatePreference(min_year, seat_number);
	return i;
}

void ClientManager::write(const std::string &directory) const {
	std::string file_path = directory + "/" + file_handling::client;

	ofstream ofstream;
	ofstream.open(file_path);

	if (!ofstream.is_open())
		throw InvalidFileException(file_path);

	for (const Client &client : clients) {
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
					 << client.getPreferenceList().getCommercialPreference()->getCargoVolume()
					 << file_handling::delimiter
					 << client.getPreferenceList().getCommercialPreference()->getMinMaxWeight()
					 << file_handling::delimiter
					 << client.getPreferenceList().getCommercialPreference()->isRefrigerated();
		}

		for (const IVehicle *vehicle : client.getVehicleList().getVehicles()) {
			ofstream << file_handling::delimiter;
			vehicle->printToFile(ofstream);
		}

		ofstream << std::endl;
	}

	ofstream.close();
}

void ClientManager::update(const ContractManager &contract_manager) {
	for (auto &client : clients) {
		if (inactive_clients.find(&client) == inactive_clients.end()) {
			long days = contract_manager.daysSinceLastContract(client.getIdentificationNumber());

			if (days >= DAYS_TO_INACTIVITY)
				inactive_clients.insert(&client);
		} else {
			long days = contract_manager.daysSinceLastContract(client.getIdentificationNumber());

			if (days < DAYS_TO_INACTIVITY)
				inactive_clients.erase(&client);
		}
	}
}

vector<const Client *> ClientManager::getInactiveClients() const {
	vector<const Client *> res;

	for (const Client *client : inactive_clients)
		res.push_back(client);

	return res;
}
