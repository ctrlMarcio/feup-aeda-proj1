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

std::ostream &operator<<(std::ostream &ostream, const CommercialPreference &commercial_preference) {
	ostream << "Commercial preference:" << std::endl;
	ostream << "Minimum year: " << commercial_preference.min_year << std::endl;
	ostream << "Minimum cargo volume: " << commercial_preference.cargo_volume << std::endl;
	ostream << "Minimum max weight: " << commercial_preference.min_max_weight << std::endl;
	if (!commercial_preference.refrigerated)
		ostream << "Not ";
	ostream << "Refrigerated." << std::endl;
	return ostream;
}
