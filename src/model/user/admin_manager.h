#ifndef FEUP_AEDA_PROJ1_ADMIN_MANAGER_H
#define FEUP_AEDA_PROJ1_ADMIN_MANAGER_H


#include <list>
#include <algorithm>
#include "admin.h"


using namespace std;


class AdminManager {
    Admin build(string name, string identification_number, string address);

    bool add(Admin &admin);

    bool remove(Admin &admin);

    bool has(Admin &admin) const;

    bool has(const string &identification_number) const;

    Admin &getClient(const string &identification_number) const;

private:
    list<Admin> admins;
};


#endif //FEUP_AEDA_PROJ1_ADMIN_MANAGER_H
