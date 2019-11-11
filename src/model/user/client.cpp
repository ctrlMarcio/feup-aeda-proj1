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
