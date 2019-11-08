#include "company.h"

#include <utility>

Company::Company(string name) : name(std::move(name)) {}

UserManager &Company::getUserManager() {
    return user_manager;
}

RentalManager &Company::getRentalManager() {
	return rental_manager;
}

OfferManager &Company::getOfferManager() {
	return offer_manager;
}

string Company::getName() const {
    return name;
}
