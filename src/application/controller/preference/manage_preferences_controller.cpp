#include "manage_preferences_controller.h"

ManagePreferencesController::ManagePreferencesController(PreferenceList &preferenceList) :
		preference_list(preferenceList) {}

bool ManagePreferencesController::addPreference(unsigned min_year, unsigned seat_number) {
	return preference_list.updatePreference(min_year, seat_number);
}

bool ManagePreferencesController::addPreference(unsigned min_year, float cargo_volume, float min_max_weight, bool refrigerated) {
	return preference_list.updatePreference(min_year, cargo_volume, min_max_weight, refrigerated);
}

void ManagePreferencesController::removePassengerPreference() {
	preference_list.removePassengerPreference();
}

void ManagePreferencesController::removeCommercialPreference() {
	preference_list.removeCommercialPreference();
}

PassengerPreference *ManagePreferencesController::getPassengerPreference() {
	return preference_list.getPassengerPreference();
}

CommercialPreference *ManagePreferencesController::getCommercialPreference() {
	return preference_list.getCommercialPreference();
}
