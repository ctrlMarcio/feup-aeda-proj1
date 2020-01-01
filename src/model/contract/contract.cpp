#include "contract.h"

Contract::Contract(Date &date, IUser *user, ContractType contract_type) : date(date), user(user),
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
