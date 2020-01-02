#ifndef FEUP_AEDA_PROJ1_CONTRACT_H
#define FEUP_AEDA_PROJ1_CONTRACT_H

#include <string>
#include "../user/i_user.h"
#include "../../util/date.h"
#include "contract_type.h"

using namespace std;

class   Contract {
public:
    Contract(Date &date, IUser *user, ContractType contract_type);

    ~Contract();

    const Date &getDate() const;

    IUser *getUser() const;

    ContractType getContractType() const;

    bool operator<(const Contract &rhs) const;

    bool operator>(const Contract &rhs) const;

    bool operator<=(const Contract &rhs) const;

    bool operator>=(const Contract &rhs) const;

	bool operator==(const Contract &rhs) const;

	bool operator!=(const Contract &rhs) const;

	string toString() const;

private:
    Date date;

    IUser *user;

    ContractType contract_type;
};


#endif //FEUP_AEDA_PROJ1_CONTRACT_H
