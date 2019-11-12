#ifndef FEUP_AEDA_PROJ1_AUTH_USER_MANAGER_H
#define FEUP_AEDA_PROJ1_AUTH_USER_MANAGER_H


#include <list>
#include "auth_user.h"


using namespace std;


class AuthUserManager {
public:
    /*!
     * Establishes a new instance of an AuthUser.
     *
     * @param identification_number the identification number
     * @param password the password
     * @return an AuthUser instance
     */
    AuthUser build(string identification_number, string password);

    /*!
     * Adds a user to the list.
     *
     * @param user reference to a user
     * @return true, if the user is successfully added. false, otherwise
     */
    bool add(AuthUser &user);

    /*!
     * Removes a user from the list.
     *
     * @param user reference to a user
     * @return true, if the user is successfully removed. false, otherwise
     */
    bool remove(AuthUser &user);

    /*!
     * Verifies if a user is in the list or not.
     *
     * @param user reference to a user
     * @return true, if the user is in the list. false, otherwise
     */
    bool has(AuthUser &user) const;

    /*!
     * Verifies if a user is in the list or not.
     *
     * @param identification_number the identification number of the user to verify
     * @return true, if the user is in the list. false, otherwise
     */
    bool has(const string &identification_number) const;

    /*!
     * Gets the user from the list given an identification number.
     *
     * @param identification_number the identification number of the user to get
     * @return the user, if found
     */
    AuthUser &getUser(const string &identification_number) const;

private:
    list<AuthUser> users;
};


#endif //FEUP_AEDA_PROJ1_AUTH_USER_MANAGER_H
