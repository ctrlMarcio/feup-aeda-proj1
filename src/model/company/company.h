#ifndef FEUP_AEDA_PROJ1_COMPANY_H
#define FEUP_AEDA_PROJ1_COMPANY_H


#include "../rental/rental_manager.h"
#include "../offer/offer_manager.h"


class Company {
private:
    string name;

	RentalManager rental_manager;

	OfferManager offer_manager;

public:
    explicit Company(string name);

    string getName() const;

	RentalManager &getRentalManager();

	OfferManager &getOfferManager();
};


#endif //FEUP_AEDA_PROJ1_COMPANY_H
