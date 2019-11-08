#ifndef FEUP_AEDA_PROJ1_USER_MANAGER_H
#define FEUP_AEDA_PROJ1_USER_MANAGER_H


#include <vector>
#include "i_user.h"


using namespace std;

class UserManager {
private:
    vector<IUser *> users;

public:
    void add(IUser *user);

    void remove(IUser *user);

    bool has(IUser *user) const;

    bool has(const string &identification_number) const;

    IUser *getUser(const string &identification_number) const;
};


#endif //FEUP_AEDA_PROJ1_USER_MANAGER_H
