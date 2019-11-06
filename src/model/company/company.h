#ifndef FEUP_AEDA_PROJ1_COMPANY_H
#define FEUP_AEDA_PROJ1_COMPANY_H


#include "model/user/user_manager.h"

class Company {
private:

    UserManager user_manager;

public:
    Company();

    UserManager &getUserManager();

};


#endif //FEUP_AEDA_PROJ1_COMPANY_H
