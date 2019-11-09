#ifndef FEUP_AEDA_PROJ1_I_RENTER_H
#define FEUP_AEDA_PROJ1_I_RENTER_H


#include <list>
#include "i_user.h"
#include "../preference/preference.h"

class IRenter : public IUser {
public:
	virtual std::list<Preference> &getPreferences() = 0;
};


#endif //FEUP_AEDA_PROJ1_I_RENTER_H
