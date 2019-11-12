#include "client_manager.h"

#include <utility>

Client ClientManager::build(string name, string identification_number, string address) {
    return Client(std::move(name), std::move(identification_number), std::move(address));
}

bool ClientManager::add(Client &client) {
    if (has(client) || has(client.getIdentificationNumber())) return false;
    clients.push_back(client);
    return true;
}

bool ClientManager::remove(Client &client) {
    if (!has(client) || !has(client.getIdentificationNumber())) return false;
    clients.erase(find(clients.begin(), clients.end(), client));
    return true;
}

bool ClientManager::has(Client &client) const {
    return find(clients.begin(), clients.end(), client) != clients.end();
}

bool ClientManager::has(const string &identification_number) const {
    return find_if(clients.begin(), clients.end(), [&identification_number](const Client &client){
        return client.getIdentificationNumber() == identification_number;
    }) != clients.end();
}

Client &ClientManager::getClient(const string &identification_number) const {
    auto it = clients.begin();

    while (it != clients.end()){
        if ((*it).getIdentificationNumber() == identification_number){
            return const_cast<Client &>(*it);
        }
        it++;
    }

    return const_cast<Client &>(*clients.end());
}
