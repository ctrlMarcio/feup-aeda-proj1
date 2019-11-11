#include "current_session.h"
#include "../../exception/invalid_login_exception.h"

CurrentSession::CurrentSession(AuthUserManager &auth_user_manager) : auth_user_manager(auth_user_manager) {}

AuthUser &CurrentSession::getUser() const {
    if (!logged) return *(new AuthUser("", ""));
    return current_user;
}

void CurrentSession::login(const string &identification_number, const string &password) {
    if (logged) throw InvalidLoginException("There is already a user logged");
    if (!auth_user_manager.has(identification_number))
        throw InvalidLoginException("There is no user with that identification number");

    AuthUser user = auth_user_manager.getUser(identification_number);

    if (user.getPassword() != password) throw InvalidLoginException("");

    current_user = user;

    logged = true;
}

void CurrentSession::logout() {
    logged = false;
}
