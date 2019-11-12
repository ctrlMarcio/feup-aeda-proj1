#include "admin_manager.h"

Admin AdminManager::build(string name, string identification_number, string address) {
    return Admin(std::move(name), std::move(identification_number), std::move(address));
}

bool AdminManager::add(Admin &admin) {
    if (has(admin) || has(admin.getIdentificationNumber())) return false;
    admins.push_back(admin);
    return true;
}

bool AdminManager::remove(Admin &admin) {
    if (!has(admin) || !has(admin.getIdentificationNumber())) return false;
    admins.erase(find(admins.begin(), admins.end(), admin));
    return true;
}

bool AdminManager::has(Admin &admin) const {
    return find(admins.begin(), admins.end(), admin) != admins.end();
}

bool AdminManager::has(const string &identification_number) const {
    return find_if(admins.begin(), admins.end(), [&identification_number](const Admin &admin){
        return admin.getIdentificationNumber() == identification_number;
    }) != admins.end();
}

Admin &AdminManager::getClient(const string &identification_number) const {
    auto it = admins.begin();

    while (it != admins.end()){
        if ((*it).getIdentificationNumber() == identification_number){
            return const_cast<Admin &>(*it);
        }
        it++;
    }

    return const_cast<Admin &>(*admins.end());
}
