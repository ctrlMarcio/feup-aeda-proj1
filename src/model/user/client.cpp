#include "client.h"

#include <utility>

Client::Client(string name, string identification_number, string address) : name(std::move(name)),
                                                                            identification_number(
                                                                                    std::move(
                                                                                            identification_number)),
                                                                            address(std::move(
                                                                                    address)) {}

VehicleList &Client::getVehicleList() {
    return vehicle_list;
}

const VehicleList &Client::getVehicleList() const {
	return vehicle_list;
}

PreferenceList Client::getPreferenceList() const {
	return preference_list;
}

PreferenceList &Client::getPreferenceList() {
    return preference_list;
}

string Client::getName() const {
    return name;
}

string Client::getIdentificationNumber() const {
    return identification_number;
}

string Client::getAddress() const {
    return address;
}

bool Client::operator==(const Client &rhs) const {
    return name == rhs.name &&
           identification_number == rhs.identification_number &&
           address == rhs.address &&
           vehicle_list == rhs.vehicle_list &&
           preference_list == rhs.preference_list;
}

void Client::print(std::ostream &ostream) const {
	ostream << name << "; ID: " << identification_number << "; Address: " << address << std::endl;
}

bool Client::operator!=(const Client &rhs) const {
    return !(rhs == *this);
}

Client &Client::operator=(const Client &client) {
	name = client.name;
	identification_number = client.identification_number;
	address = client.address;
	vehicle_list = client.vehicle_list;
	preference_list = client.preference_list;

	return *this;
}
