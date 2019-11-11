#include "client_company.h"

#include <utility>

ClientCompany::ClientCompany(string name, string identification_number, string address, string password) : name(
        std::move(name)),
                                                                                                           identification_number(
                                                                                                                   std::move(
                                                                                                                           identification_number)),
                                                                                                           address(std::move(
                                                                                                                   address)),
                                                                                                           password(
                                                                                                                   std::move(
                                                                                                                           password)) {}

string ClientCompany::getName() const {
    return name;
}

string ClientCompany::getIdentificationNumber() const {
    return identification_number;
}

string ClientCompany::getAddress() const {
    return address;
}

string ClientCompany::getPassword() const {
    return password;
}

list<Preference> &ClientCompany::getPreferences() {
    return preferences;
}
