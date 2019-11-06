#include "company.h"

Company::Company() = default;

UserManager &Company::getUserManager() {
    return user_manager;
}

RentalManager &Company::getRentalManager() {
	return rental_manager;
}
