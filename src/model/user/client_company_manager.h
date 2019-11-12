#ifndef FEUP_AEDA_PROJ1_CLIENT_COMPANY_MANAGER_H
#define FEUP_AEDA_PROJ1_CLIENT_COMPANY_MANAGER_H


#include <list>
#include <algorithm>
#include "client_company.h"


using namespace std;

class ClientCompanyManager {
    ClientCompany build(string name, string identification_number, string address);

    bool add(ClientCompany &client);

    bool remove(ClientCompany &client);

    bool has(ClientCompany &client) const;

    bool has(const string &identification_number) const;

    ClientCompany &getClient(const string &identification_number) const;

private:
    list<ClientCompany> clients;
};


#endif //FEUP_AEDA_PROJ1_CLIENT_COMPANY_MANAGER_H
