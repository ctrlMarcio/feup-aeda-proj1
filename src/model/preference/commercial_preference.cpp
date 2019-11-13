#include "commercial_preference.h"

CommercialPreference::CommercialPreference(unsigned int minYear, float cargoVolume, float minMaxWeight, bool refrigerated) :
		min_year(minYear), cargo_volume(cargoVolume), min_max_weight(minMaxWeight), refrigerated(refrigerated) {}

unsigned int CommercialPreference::getMinYear() const {
	return min_year;
}

float CommercialPreference::getCargoVolume() const {
	return cargo_volume;
}

float CommercialPreference::getMinMaxWeight() const {
	return min_max_weight;
}

bool CommercialPreference::isRefrigerated() const {
	return refrigerated;
}
