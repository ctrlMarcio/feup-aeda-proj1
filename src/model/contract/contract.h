#ifndef FEUP_AEDA_PROJ1_CONTRACT_H
#define FEUP_AEDA_PROJ1_CONTRACT_H

#include <string>
#include "../user/i_user.h"
#include "../../util/date.h"
#include "contract_type.h"
#include "../offer/offer.h"

using namespace std;

class Contract {
public:
    Contract(Date date, IUser *user, ContractType contract_type);

    const Date &getDate() const;

    IUser *getUser() const;

    ContractType getContractType() const;

	virtual const Offer &getOffer() const = 0;

    bool operator<(const Contract &rhs) const;

    bool operator>(const Contract &rhs) const;

    bool operator<=(const Contract &rhs) const;

    bool operator>=(const Contract &rhs) const;

    bool operator==(const Contract &rhs) const;

    bool operator!=(const Contract &rhs) const;

    string toString();

private:
    Date date;

    IUser *user;

    ContractType contract_type;
};


#endif //FEUP_AEDA_PROJ1_CONTRACT_H
