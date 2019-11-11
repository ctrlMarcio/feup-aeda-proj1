#include "client_company.h"

#include <utility>

ClientCompany::ClientCompany(string name, string identification_number, string address) : name(
        std::move(name)),
                                                                                          identification_number(
                                                                                                  std::move(
                                                                                                          identification_number)),
                                                                                          address(std::move(
                                                                                                  address)) {}

string ClientCompany::getName() const {
    return name;
}

string ClientCompany::getIdentificationNumber() const {
    return identification_number;
}

string ClientCompany::getAddress() const {
    return address;
}

PreferenceList &ClientCompany::getPreferenceList() {
    return preference_list;
}