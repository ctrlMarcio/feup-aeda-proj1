#include "auth_user_manager.h"

#include <utility>
#include <algorithm>

AuthUser AuthUserManager::build(string identification_number, string password) {
    return AuthUser(std::move(identification_number), std::move(password));
}

bool AuthUserManager::add(AuthUser &user) {
    if (has(user) || has(user.getIdentificationNumber())) return false;
    users.push_back(user);
    return true;
}

bool AuthUserManager::remove(AuthUser &user) {
    if (!has(user) || !has(user.getIdentificationNumber())) return false;
    users.erase(find(users.begin(), users.end(), user));
    return true;
}

bool AuthUserManager::has(AuthUser &user) const {
    return find(users.begin(), users.end(), user) != users.end();
}

bool AuthUserManager::has(const string &identification_number) const {
    return find_if(users.begin(), users.end(), [&identification_number](const AuthUser &user) {
        return user.getIdentificationNumber() == identification_number;
    }) != users.end();
}

AuthUser &AuthUserManager::getUser(const string &identification_number) const {
    auto it = users.begin();

    while (it != users.end()){
        if ((*it).getIdentificationNumber() == identification_number){
            return const_cast<AuthUser &>(*it);
        }
        it++;
    }

    return const_cast<AuthUser &>(*users.end());
}
