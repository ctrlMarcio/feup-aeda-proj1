#ifndef FEUP_AEDA_PROJ1_REGISTER_PAGE_CONTROLLER_H
#define FEUP_AEDA_PROJ1_REGISTER_PAGE_CONTROLLER_H


#include "../../../auth/auth_user/auth_user_manager.h"
#include "../../../model/company/company.h"
#include <string>


using namespace std;


class RegisterPageController {
public:
    RegisterPageController(AuthUserManager &auth_user_manager, Company &company);

    bool hasUser(const string &identification_number);

    bool createUser(const string &role, const string &name, const string &identification_number, const string &address);

    string getPassword(const string &identification_number);

private:
    AuthUserManager &auth_user_manager;

    Company &company;
};


#endif //FEUP_AEDA_PROJ1_REGISTER_PAGE_CONTROLLER_H
