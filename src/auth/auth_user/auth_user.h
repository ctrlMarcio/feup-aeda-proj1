#ifndef FEUP_AEDA_PROJ1_AUTH_USER_H
#define FEUP_AEDA_PROJ1_AUTH_USER_H


#include <string>


using namespace std;


class AuthUser {
public:
    AuthUser(string identification_number, string password);

    const string &getIdentificationNumber() const;

    const string &getPassword() const;

    bool operator==(const AuthUser &rhs) const;

    bool operator!=(const AuthUser &rhs) const;

private:
    string identification_number;

    string password;
};


#endif //FEUP_AEDA_PROJ1_AUTH_USER_H
