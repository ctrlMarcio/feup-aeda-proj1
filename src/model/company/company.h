#ifndef FEUP_AEDA_PROJ1_COMPANY_H
#define FEUP_AEDA_PROJ1_COMPANY_H


#include "../user/user_manager.h"
#include "../rental/rental_manager.h"

class Company {
private:
    UserManager user_manager;

	RentalManager rental_manager;

public:
    Company();

    UserManager &getUserManager();

	RentalManager &getRentalManager();
};


#endif //FEUP_AEDA_PROJ1_COMPANY_H
