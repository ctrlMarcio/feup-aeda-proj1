#ifndef FEUP_AEDA_PROJ1_AUTH_USER_H
#define FEUP_AEDA_PROJ1_AUTH_USER_H


#include <string>
#include "../../util/date.h"


using namespace std;


/*!
 * Represents an authentication user.
 */
class AuthUser {
public:
    /*!
     * The admin role.
     */
    static const string ADMIN_ROLE;

    /*!
     * The client role.
     */
    static const string CLIENT_ROLE;

    /*!
     * The client company role.
     */
    static const string CLIENT_COMPANY_ROLE;

    /*!
     * Establishes a new instance of an AuthUser.
     *
     * @param identification_number the identification number
     * @param password the password
     * @param user_role the user role
     */
    AuthUser(string identification_number, string password, string user_role);

    /*!
     * Gets the identification number.
     *
     * @return the identification number
     */
    const string &getIdentificationNumber() const;

    /*!
     * Gets the password.
     *
     * @return the password
     */
    const string &getPassword() const;

    /*!
     * Gets the role.
     *
     * @return the role
     */
    const string &getRole() const;

    bool operator==(const AuthUser &rhs) const;

    bool operator!=(const AuthUser &rhs) const;

private:
    /*!
     * The identification number.
     */
    string identification_number;

    /*!
     * The password.
     */
    string password;

    /*!
     * The user role.
     */
    string user_role;
};


#endif //FEUP_AEDA_PROJ1_AUTH_USER_H
