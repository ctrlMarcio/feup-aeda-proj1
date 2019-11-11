#include "auth_user.h"

#include <utility>
#include <stdexcept>

AuthUser::AuthUser(string identification_number, string password) : identification_number(
        std::move(identification_number)),
                                                                    password(std::move(password)) {}

const string &AuthUser::getIdentificationNumber() const {
    return identification_number;
}

const string &AuthUser::getPassword() const {
    return password;
}

bool AuthUser::operator==(const AuthUser &rhs) const {
    return identification_number == rhs.identification_number &&
           password == rhs.password;
}

bool AuthUser::operator!=(const AuthUser &rhs) const {
    return !(rhs == *this);
}
