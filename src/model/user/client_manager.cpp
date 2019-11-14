#include "client_manager.h"

#include <utility>
#include <fstream>
#include "../../application/io/file_handling.h"
#include "../../exception/invalid_file_exception.h"
#include "../../util/string_util.h"

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

Client &ClientManager::get(const string &identification_number) const {
	auto it = clients.begin();

	while (it != clients.end()) {
		if ((*it).getIdentificationNumber() == identification_number) {
			return const_cast<Client &>(*it);
		}
		it++;
	}

	return const_cast<Client &>(*clients.end());
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
		if (params[i] == "passenger_pref")
			i = readPassengerPreference(params, client, i);

		if (params[i] == "commercial_pref")
			i = readCommercialPreference(params, client, i);

		for (; i < params.size(); ++i) {
			if (params[i] == "passenger")
				i = readPassengerVehicle(params, client, i);
			else if (params[i] == "commercial")
				i = readCommercialVehicle(params, client, i);
			else
				break;
		}
		this->add(*client);
	}

	ifstream.close();
}

size_t ClientManager::readCommercialVehicle(const vector<std::string> &params, Client *client, size_t i) const {
	string number_plate = params[++i];
	string brand = params[++i];
	string model = params[++i];
	unsigned year = stoul(params[++i]);
	float cargo_volume = stof(params[++i]);
	float min_max_weight = stof(params[++i]);
	++i;
	bool refrigerated = params[i] == "y" || params[i] == "yes" || params[i] == "1" || params[i] == "t" || params[i] == "true";


	client->getVehicleList().add(&VehicleList::build(number_plate, brand, model, year, cargo_volume, min_max_weight, refrigerated));
	return i;
}

size_t ClientManager::readPassengerVehicle(const vector<std::string> &params, Client *client, size_t i) const {
	string number_plate = params[++i];
	string brand = params[++i];
	string model = params[++i];
	unsigned year = stoul(params[++i]);
	unsigned seat_number = stoul(params[++i]);

	client->getVehicleList().add(&VehicleList::build(number_plate, brand, model, year, seat_number));
	return i;
}

size_t ClientManager::readCommercialPreference(const vector<std::string> &params, Client *client, size_t i) const {
	unsigned min_year = stoul(params[++i]);
	float cargo_volume = stof(params[++i]);
	float min_max_weight = stof(params[++i]);
	++i;
	bool refrigerated = params[i] == "y" || params[i] == "yes" || params[i] == "1" || params[i] == "t" || params[i] == "true";
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
					 << client.getPreferenceList().getCommercialPreference()->getCargoVolume() << file_handling::delimiter
					 << client.getPreferenceList().getCommercialPreference()->getMinMaxWeight() << file_handling::delimiter
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
