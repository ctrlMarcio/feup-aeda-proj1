#ifndef FEUP_AEDA_PROJ1_PREFERENCE_LIST_H
#define FEUP_AEDA_PROJ1_PREFERENCE_LIST_H


#include "passenger_preference.h"
#include "commercial_preference.h"

class PreferenceList {
public:
	bool updatePreference(unsigned min_year, unsigned seat_number);

	bool updatePreference(unsigned min_year, float cargo_volume, float min_max_weight, bool refrigerated);

	PassengerPreference *getPassengerPreference() const;

	CommercialPreference *getCommercialPreference();

	void removePassengerPreference();

	void removeCommercialPreference();

	bool operator==(const PreferenceList &rhs) const;

    bool operator!=(const PreferenceList &rhs) const;

private:
	PassengerPreference *passenger_preference = nullptr;

	CommercialPreference *commercial_preference = nullptr;

	bool isValid(PassengerPreference preference) const;

	bool isValid(CommercialPreference preference) const;
};


#endif //FEUP_AEDA_PROJ1_PREFERENCE_LIST_H
