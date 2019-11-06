#include "current_session.h"

CurrentSession::CurrentSession(Company &company) : company(company) {}

IUser *CurrentSession::getUser() const {
    return current_user;
}

void CurrentSession::login(const string& identification_number, const string& password) {
    if (!company.getUserManager().has(identification_number)) return;

    IUser *user = company.getUserManager().getUser(identification_number);

    if (user->getPassword() == password) current_user = user;
}

void CurrentSession::logout() {
    current_user = nullptr;
}
