#include "company.h"

Company::Company() = default;

UserManager &Company::getUserManager() {
    return user_manager;
}

RentalManager &Company::getRentalManager() {
	return rental_manager;
}

OfferManager &Company::getOfferManager() {
	return offer_manager;
}