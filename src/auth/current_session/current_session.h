#ifndef FEUP_AEDA_PROJ1_CURRENT_SESSION_H
#define FEUP_AEDA_PROJ1_CURRENT_SESSION_H


#include "../auth_user/auth_user.h"
#include "../auth_user/auth_user_manager.h"

class CurrentSession {
private:
    AuthUser &current_user = *(new AuthUser("", ""));

    AuthUserManager &auth_user_manager;

    bool logged = false;

public:
    explicit CurrentSession(AuthUserManager &auth_user_manager);

    AuthUser &getUser() const;

    void login(const string &identification_number, const string &password);

    void logout();
};


#endif //FEUP_AEDA_PROJ1_CURRENT_SESSION_H
