#ifndef FEUP_AEDA_PROJ1_USER_MANAGER_H
#define FEUP_AEDA_PROJ1_USER_MANAGER_H


#include <vector>
#include "i_user.h"


using namespace std;


/*!
 * A UserManager stores and handles operations between the system users.
 */
class UserManager {
private:
    /*!
     * The list of users.
     */
    vector<IUser *> users;

public:
    /*!
     * Adds a user to the list.
     *
     * @param user pointer to an implementation of IUser
     */
    void add(IUser *user);

    /*!
     * Removes a user from the list.
     *
     * @param user pointer to an implementation of IUser
     */
    void remove(IUser *user);

    /*!
     * Verifies if a user is in the list or not.
     *
     * @param user pointer to an implementation of IUser
     * @return true, if the user is in the list. false, otherwise
     */
    bool has(IUser *user) const;

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
    IUser *getUser(const string &identification_number) const;
};


#endif //FEUP_AEDA_PROJ1_USER_MANAGER_H
