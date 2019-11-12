#ifndef FEUP_AEDA_PROJ1_PREFERENCE_LIST_H
#define FEUP_AEDA_PROJ1_PREFERENCE_LIST_H


#include "passenger_preference.h"
#include "commercial_preference.h"

class PreferenceList {
public:
	bool addPreference(unsigned min_year, unsigned seat_number);

	bool addPreference(unsigned min_year, float cargo_volume, float min_max_weight, bool refrigerated);

    bool operator==(const PreferenceList &rhs) const;

    bool operator!=(const PreferenceList &rhs) const;

private:
	PassengerPreference *passenger_preference;

	CommercialPreference *commercial_preference;

	bool isValid(PassengerPreference preference) const;

	bool isValid(CommercialPreference preference) const;
};


#endif //FEUP_AEDA_PROJ1_PREFERENCE_LIST_H
