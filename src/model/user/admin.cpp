#include "admin.h"

#include <utility>

Admin::Admin(string name, string identification_number, string address) : name(std::move(name)),
                                                                          identification_number(
                                                                                  std::move(
                                                                                          identification_number)),
                                                                          address(std::move(address)) {}

string Admin::getName() const {
    return name;
}

string Admin::getIdentificationNumber() const {
    return identification_number;
}

string Admin::getAddress() const {
    return address;
}
