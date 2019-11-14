#ifndef FEUP_AEDA_PROJ1_LOGIN_PAGE_CONTROLLER_H
#define FEUP_AEDA_PROJ1_LOGIN_PAGE_CONTROLLER_H


#include "../../../auth/auth_user/auth_user_manager.h"
#include "../../../auth/current_session/current_session.h"
#include "../../ui/ui_manager.h"


class LoginPageController {
public:
    LoginPageController(CurrentSession &current_session, AuthUserManager &auth_user_manager, UIManager &ui_manager);

    bool hasUser(const string &identification_number);

    bool login(const string &identification_number, const string &password);

    void redirect(const string &identification_number);

private:
    CurrentSession &current_session;

    AuthUserManager &auth_user_manager;

    UIManager &ui_manager;
};


#endif //FEUP_AEDA_PROJ1_LOGIN_PAGE_CONTROLLER_H
