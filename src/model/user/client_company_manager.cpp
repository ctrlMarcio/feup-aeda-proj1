#include "client_company_manager.h"

ClientCompany ClientCompanyManager::build(string name, string identification_number, string address) {
    return ClientCompany(std::move(name), std::move(identification_number), std::move(address));
}

bool ClientCompanyManager::add(ClientCompany &client) {
    if (has(client) || has(client.getIdentificationNumber())) return false;
    clients.push_back(client);
    return true;
}

bool ClientCompanyManager::remove(ClientCompany &client) {
    if (!has(client) || !has(client.getIdentificationNumber())) return false;
    clients.erase(find(clients.begin(), clients.end(), client));
    return true;
}

bool ClientCompanyManager::has(ClientCompany &client) const {
    return find(clients.begin(), clients.end(), client) != clients.end();
}

bool ClientCompanyManager::has(const string &identification_number) const {
    return find_if(clients.begin(), clients.end(), [&identification_number](const ClientCompany &client) {
        return client.getIdentificationNumber() == identification_number;
    }) != clients.end();
}

ClientCompany &ClientCompanyManager::getClient(const string &identification_number) const {
    auto it = clients.begin();

    while (it != clients.end()) {
        if ((*it).getIdentificationNumber() == identification_number) {
            return const_cast<ClientCompany &>(*it);
        }
        it++;
    }

    return const_cast<ClientCompany &>(*clients.end());
}
