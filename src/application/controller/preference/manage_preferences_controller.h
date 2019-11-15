#ifndef FEUP_AEDA_PROJ1_MANAGE_PREFERENCES_CONTROLLER_H
#define FEUP_AEDA_PROJ1_MANAGE_PREFERENCES_CONTROLLER_H


#include "../../../model/preference/preference_list.h"

class ManagePreferencesController {
public:
	explicit ManagePreferencesController(PreferenceList &preferenceList);

	bool addPreference(unsigned min_year, unsigned seat_number);

	bool addPreference(unsigned min_year, float cargo_volume, float min_max_weight, bool refrigerated);

	void removePassengerPreference();

	void removeCommercialPreference();

	PassengerPreference *getPassengerPreference();

	CommercialPreference *getCommercialPreference();

private:
	PreferenceList &preference_list;
};


#endif //FEUP_AEDA_PROJ1_MANAGE_PREFERENCES_CONTROLLER_H
