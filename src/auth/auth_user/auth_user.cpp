#include "auth_user.h"

#include <utility>
#include <stdexcept>

const string AuthUser::ADMIN_ROLE = "admin";

const string AuthUser::CLIENT_ROLE = "client";

const string AuthUser::CLIENT_COMPANY_ROLE = "company_client";

AuthUser::AuthUser(string identification_number, string password, string user_role) : identification_number(
        std::move(identification_number)), password(std::move(password)), user_role(std::move(user_role)) {}

const string &AuthUser::getIdentificationNumber() const {
    return identification_number;
}

const string &AuthUser::getPassword() const {
    return password;
}

const string &AuthUser::getRole() const {
    return user_role;
}

bool AuthUser::operator==(const AuthUser &rhs) const {
    return identification_number == rhs.identification_number &&
           password == rhs.password &&
           user_role == rhs.user_role;
}

bool AuthUser::operator!=(const AuthUser &rhs) const {
    return !(rhs == *this);
}
