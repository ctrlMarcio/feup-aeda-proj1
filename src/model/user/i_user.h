#ifndef FEUP_AEDA_PROJ1_I_USER_H
#define FEUP_AEDA_PROJ1_I_USER_H


#include <string>
#include <iostream>


using namespace std;


/*!
 * A IUser provides the data implementation for the system users.
 */
class IUser {
public:
    /*!
     * Gets the name of this user.
     *
     * @return the name
     */
    virtual string getName() const = 0;

    /*!
     * Gets the identification number of this user. The identification number is unique and associated to a government
     * unique number such as the tax identification number.
     *
     * @return the identification number
     */
    virtual string getIdentificationNumber() const = 0;

    /*!
     * Gets the address of this user. The address follows the following format: [street name] [door number],
     * [postal town (town/city)], [postal code], [country name].
     *
     * Example: Oxford Road 28, Aylesbury, HP19 3EQ, United Kingdom
     *
     * @return the address
     */
    virtual string getAddress() const = 0;
};


#endif //FEUP_AEDA_PROJ1_I_USER_H
