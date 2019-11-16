#ifndef FEUP_AEDA_PROJ1_CURRENT_SESSION_H
#define FEUP_AEDA_PROJ1_CURRENT_SESSION_H


#include "../auth_user/auth_user.h"
#include "../auth_user/auth_user_manager.h"


/*!
 * Represents the current session.
 */
class CurrentSession {
private:
    /*!
     * The current user.
     */
    AuthUser &current_user = *(new AuthUser("", "", ""));

    /*!
     * The auth user manager.
     */
    AuthUserManager &auth_user_manager;

    /*!
     * The current user status.
     */
    bool logged = false;

public:
    /*!
     * Establishes a new instance of a CurrentSession.
     *
     * @param auth_user_manager the auth user manager
     */
    explicit CurrentSession(AuthUserManager &auth_user_manager);

    /*!
     * Gets the current user.
     *
     * @return the user
     */
    AuthUser &getUser() const;

    /*!
     * Tries to login a user given its information.
     *
     * @param identification_number the identification number.
     * @param password the password
     */
    void login(const string &identification_number, const string &password);

    /*!
     * Logs out a user.
     */
    void logout();
};


#endif //FEUP_AEDA_PROJ1_CURRENT_SESSION_H
