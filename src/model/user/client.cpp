#include "client.h"

#include <utility>

Client::Client(string name, string identification_number, string address, string password) : name(std::move(name)),
                                                                                             identification_number(
                                                                                                     std::move(
                                                                                                             identification_number)),
                                                                                             address(std::move(
                                                                                                     address)),
                                                                                             password(std::move(
                                                                                                     password)) {}

VehicleList &Client::getVehicleList() {
    return vehicle_list;
}

list<Preference> &Client::getPreferences() {
    return preferences;
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

string Client::getPassword() const {
    return password;
}
