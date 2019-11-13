#ifndef FEUP_AEDA_PROJ1_AUTH_USER_H
#define FEUP_AEDA_PROJ1_AUTH_USER_H


#include <string>


using namespace std;


class AuthUser {
public:
    static const string ADMIN_ROLE;

    static const string CLIENT_ROLE;

    static const string CLIENT_COMPANY_ROLE;

    AuthUser(string identification_number, string password, string user_role);

    const string &getIdentificationNumber() const;

    const string &getPassword() const;

    const string &getRole() const;

    bool operator==(const AuthUser &rhs) const;

    bool operator!=(const AuthUser &rhs) const;

private:
    string identification_number;

    string password;

    string user_role;
};


#endif //FEUP_AEDA_PROJ1_AUTH_USER_H
