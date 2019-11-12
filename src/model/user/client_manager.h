#ifndef FEUP_AEDA_PROJ1_CLIENT_MANAGER_H
#define FEUP_AEDA_PROJ1_CLIENT_MANAGER_H


#include <list>
#include <algorithm>
#include "client.h"

using namespace std;


class ClientManager {
public:
    Client build(string name, string identification_number, string address);

    bool add(Client &client);

    bool remove(Client &client);

    bool has(Client &client) const;

    bool has(const string &identification_number) const;

    Client &getClient(const string &identification_number) const;

private:
    list<Client> clients;
};


#endif //FEUP_AEDA_PROJ1_CLIENT_MANAGER_H
