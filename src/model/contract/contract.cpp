#include "contract.h"
#include "../../util/string_util.h"
#include <sstream>

Contract::Contract(Date date, IUser *user, ContractType contract_type) : date(date), user(user),
                                                                         contract_type(contract_type) {}

Contract::~Contract() {
    delete user;
}

const Date &Contract::getDate() const {
    return date;
}

IUser *Contract::getUser() const {
    return user;
}

ContractType Contract::getContractType() const {
    return contract_type;
}

bool Contract::operator<(const Contract &rhs) const {
    if (date < rhs.date)
        return true;
    if (rhs.date < date)
        return false;
    return user->getName() < rhs.user->getName();
}

bool Contract::operator>(const Contract &rhs) const {
    return rhs < *this;
}

bool Contract::operator<=(const Contract &rhs) const {
    return !(rhs < *this);
}

bool Contract::operator>=(const Contract &rhs) const {
    return !(*this < rhs);
}

bool Contract::operator==(const Contract &rhs) const {
    return date == rhs.date &&
           user->getIdentificationNumber() == rhs.user->getIdentificationNumber() &&
           contract_type == rhs.contract_type;
}

bool Contract::operator!=(const Contract &rhs) const {
    return !(rhs == *this);
}

string Contract::toString() {
    stringstream to_string_stream;

    string contract_type_string = contract_type == TRANSFER ? "Transfer" : "Rental";

    to_string_stream << contract_type_string << " contract" << " concluded on " << date.toString()
                     << " by "
                     << user->getName() << ". " << getOffer().getVehicle().getYear() << " "
                     << getOffer().getVehicle().getBrand() << " " << getOffer().getVehicle().getModel() << " ["
                     << getOffer().getVehicle().getNumberPlate() << "]";

    return to_string_stream.str();
}
