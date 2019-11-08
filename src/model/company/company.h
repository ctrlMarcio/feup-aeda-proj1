#ifndef FEUP_AEDA_PROJ1_COMPANY_H
#define FEUP_AEDA_PROJ1_COMPANY_H


#include "../user/user_manager.h"
#include "../rental/rental_manager.h"
#include "../offer/offer_manager.h"


class Company {
private:
    string name;

    UserManager user_manager;

	RentalManager rental_manager;

	OfferManager offer_manager;

public:
    explicit Company(string name);

    UserManager &getUserManager();

	RentalManager &getRentalManager();

	OfferManager &getOfferManager();

	string getName() const;
};


#endif //FEUP_AEDA_PROJ1_COMPANY_H
