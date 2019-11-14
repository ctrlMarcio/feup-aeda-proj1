#ifndef FEUP_AEDA_PROJ1_COMPANY_H
#define FEUP_AEDA_PROJ1_COMPANY_H


#include "../rental/rental_manager.h"
#include "../offer/offer_manager.h"
#include "user_manager.h"


class Company {
public:
	explicit Company(string name);

	void read(const std::string &directory);

	void write(const std::string &directory);

	string getName() const;

	UserManager &getUserManager();

	RentalManager &getRentalManager();

	OfferManager &getOfferManager();

private:
    string name;

	UserManager user_manager;

	OfferManager offer_manager;

	RentalManager rental_manager;

	VehicleList vehicleList;
};


#endif //FEUP_AEDA_PROJ1_COMPANY_H
