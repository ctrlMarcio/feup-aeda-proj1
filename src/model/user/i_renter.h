#ifndef FEUP_AEDA_PROJ1_I_RENTER_H
#define FEUP_AEDA_PROJ1_I_RENTER_H


#include <list>
#include "i_user.h"

/*!
 * A IRenter provides the data implementation for the system renters. Derives from IUser.
 */
class IRenter : public IUser {
public:
    /*!
     * Gets the preference list of this renter.
     *
     * @return the preference list
     */
	virtual PreferenceList getPreferenceList() const = 0;

    /*!
     * Gets the preference list of this renter.
     *
     * @return the preference list
     */
	virtual PreferenceList &getPreferenceList() = 0;
};


#endif //FEUP_AEDA_PROJ1_I_RENTER_H
