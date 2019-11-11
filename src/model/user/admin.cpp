#include "admin.h"

#include <utility>

Admin::Admin(string name, string identification_number, string address, string password) : name(std::move(name)),
                                                                                           identification_number(
                                                                                                   std::move(
                                                                                                           identification_number)),
                                                                                           address(std::move(address)),
                                                                                           password(std::move(
                                                                                                   password)) {}

string Admin::getName() const {
    return name;
}

string Admin::getIdentificationNumber() const {
    return identification_number;
}

string Admin::getAddress() const {
    return address;
}

string Admin::getPassword() const {
    return password;
}
