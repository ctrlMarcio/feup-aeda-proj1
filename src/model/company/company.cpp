#include "company.h"

#include <utility>

Company::Company(string name) : name(std::move(name)) {}

string Company::getName() const {
    return name;
}

RentalManager &Company::getRentalManager() {
	return rental_manager;
}

OfferManager &Company::getOfferManager() {
	return offer_manager;
}
