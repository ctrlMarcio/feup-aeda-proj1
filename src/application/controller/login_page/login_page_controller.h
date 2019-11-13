#ifndef FEUP_AEDA_PROJ1_LOGIN_PAGE_CONTROLLER_H
#define FEUP_AEDA_PROJ1_LOGIN_PAGE_CONTROLLER_H


#include "../../../auth/auth_user/auth_user_manager.h"
#include "../../../auth/current_session/current_session.h"


class LoginPageController {
public:
    LoginPageController(CurrentSession &current_session, AuthUserManager &auth_user_manager);

    bool hasUser(const string &identification_number);

private:
    CurrentSession &current_session;

    AuthUserManager &auth_user_manager;

};


#endif //FEUP_AEDA_PROJ1_LOGIN_PAGE_CONTROLLER_H
