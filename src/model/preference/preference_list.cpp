#include "../../model/user/client.h"
#include "preference_list.h"

bool PreferenceList::addPreference(unsigned min_year, unsigned seat_number) {
	auto *preference = new PassengerPreference(min_year, seat_number);

	if (!isValid(*preference))
		return false;

	this->passenger_preference = preference;
	return true;
}

bool PreferenceList::addPreference(unsigned min_year, float cargo_volume, float min_max_weight, bool refrigerated) {
	auto *preference = new CommercialPreference(min_year, cargo_volume, min_max_weight, refrigerated);

	if (!isValid(*preference))
		return false;

	this->commercial_preference = preference;
	return true;
}

bool PreferenceList::isValid(PassengerPreference preference) const {
	// TODO
	return true;
}

bool PreferenceList::isValid(CommercialPreference preference) const {
	// TODO
	return true;
}

bool PreferenceList::operator==(const PreferenceList &rhs) const {
    return passenger_preference == rhs.passenger_preference &&
           commercial_preference == rhs.commercial_preference;
}

bool PreferenceList::operator!=(const PreferenceList &rhs) const {
    return !(rhs == *this);
}
