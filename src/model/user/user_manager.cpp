#include <algorithm>
#include "user_manager.h"

void UserManager::add(IUser *user) {
    users.push_back(user);
}

void UserManager::remove(IUser *user) {
    if (!has(user)) return;
}

bool UserManager::has(IUser *user) const {
    const string &identification_number = user->getIdentificationNumber();
    return find_if(users.begin(), users.end(), [&identification_number](IUser *user) {
        return user->getIdentificationNumber() == identification_number;
    }) != users.end();
}

bool UserManager::has(const string &identification_number) const {
    return find_if(users.begin(), users.end(), [&identification_number](IUser *user) {
        return user->getIdentificationNumber() == identification_number;
    }) != users.end();
}

IUser *UserManager::getUser(const string &identification_number) const {
    return *find_if(users.begin(), users.end(), [&identification_number](IUser *user) {
        return user->getIdentificationNumber() == identification_number;
    });
}
