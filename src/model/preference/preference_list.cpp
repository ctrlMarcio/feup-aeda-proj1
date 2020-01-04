#include "../../model/vehicle/passenger_vehicle.h"
#include "../../model/vehicle/commercial_vehicle.h"
#include "../../model/user/client.h"
#include "preference_list.h"

bool PreferenceList::updatePreference(unsigned min_year, unsigned seat_number) {
	auto *preference = new PassengerPreference(min_year, seat_number);

	if (!isValid(*preference))
		return false;

	delete passenger_preference;
	this->passenger_preference = preference;
	return true;
}

bool PreferenceList::updatePreference(unsigned min_year, float cargo_volume, float min_max_weight, bool refrigerated) {
	auto *preference = new CommercialPreference(min_year, cargo_volume, min_max_weight, refrigerated);

	if (!isValid(*preference))
		return false;

	delete commercial_preference;
	this->commercial_preference = preference;
	return true;
}

bool PreferenceList::isValid(PassengerPreference preference) const {
	try {
		PassengerVehicle("", "", "", preference.getMinYear(), 0);
		return true;
	} catch (exception &e) {
		return false;
	}
}

bool PreferenceList::isValid(CommercialPreference preference) const {
	try {
		CommercialVehicle("", "", "", preference.getMinYear(), 0, 0, true);
		return true;
	} catch (exception &e) {
		return false;
	}
}

bool PreferenceList::operator==(const PreferenceList &rhs) const {
	// TODO too complex
	bool one_pass_null = false;
	bool two_pass_null = false;
	bool one_comm_null = false;
	bool two_comm_null = false;

	if (passenger_preference == nullptr || rhs.passenger_preference == nullptr) {
		if (passenger_preference == nullptr && rhs.passenger_preference == nullptr)
			two_pass_null = true;
		else
			one_pass_null = true;
	}

	if (commercial_preference == nullptr || rhs.commercial_preference == nullptr) {
		if (commercial_preference == nullptr && rhs.commercial_preference == nullptr)
			two_comm_null = true;
		else
			one_comm_null = true;
	}

	if (one_pass_null || one_comm_null)
		return false;

	if (two_pass_null && !two_comm_null)
		return *commercial_preference == *rhs.commercial_preference;

	if (!two_pass_null && two_comm_null)
		return *passenger_preference == *rhs.passenger_preference;

	if (two_pass_null && two_comm_null)
		return true;

	return *passenger_preference == *rhs.passenger_preference &&
		   *commercial_preference == *rhs.commercial_preference;
}

bool PreferenceList::operator!=(const PreferenceList &rhs) const {
	return !(rhs == *this);
}

PassengerPreference *PreferenceList::getPassengerPreference() const {
	return passenger_preference;
}

CommercialPreference *PreferenceList::getCommercialPreference() const {
	return commercial_preference;
}

void PreferenceList::removePassengerPreference() {
	delete passenger_preference;
	this->passenger_preference = nullptr;
}

void PreferenceList::removeCommercialPreference() {
	delete commercial_preference;
	this->commercial_preference = nullptr;
}

PreferenceList &PreferenceList::operator=(const PreferenceList &rhs) {
	if (passenger_preference) {
		delete passenger_preference;
		if (rhs.passenger_preference)
			passenger_preference = new PassengerPreference(rhs.passenger_preference->getMinYear(),
														   rhs.passenger_preference->getSeatNumber());
	}
	if (commercial_preference) {
		delete commercial_preference;
		if (rhs.commercial_preference)
			commercial_preference = new CommercialPreference(rhs.commercial_preference->getMinYear(),
															 rhs.commercial_preference->getCargoVolume(),
															 rhs.commercial_preference->getMinMaxWeight(),
															 rhs.commercial_preference->isRefrigerated());
	}
	return *this;
}
