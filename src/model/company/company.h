#ifndef FEUP_AEDA_PROJ1_COMPANY_H
#define FEUP_AEDA_PROJ1_COMPANY_H


#include "../rental/rental_manager.h"
#include "../offer/offer_manager.h"
#include "../user/user_manager.h"


class Company {
private:
    string name;

	UserManager user_manager;

	OfferManager offer_manager;

	RentalManager rental_manager;

public:
    explicit Company(string name);

    string getName() const;

	UserManager &getUserManager();

	RentalManager &getRentalManager();

	OfferManager &getOfferManager();
};


#endif //FEUP_AEDA_PROJ1_COMPANY_H
