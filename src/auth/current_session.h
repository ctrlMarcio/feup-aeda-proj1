#ifndef FEUP_AEDA_PROJ1_CURRENT_SESSION_H
#define FEUP_AEDA_PROJ1_CURRENT_SESSION_H


#include "../model/user/i_user.h"
#include "../model/company/company.h"

class CurrentSession {
private:
    IUser *current_user = nullptr;

    Company &company;

public:
    explicit CurrentSession(Company &company);

    IUser *getUser() const;

    void login(const string& identification_number, const string& password);

    void logout();
};


#endif //FEUP_AEDA_PROJ1_CURRENT_SESSION_H
