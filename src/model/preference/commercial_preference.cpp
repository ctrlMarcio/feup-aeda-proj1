#include "commercial_preference.h"

CommercialPreference::CommercialPreference(unsigned int minYear, float cargoVolume, float minMaxWeight, bool refrigerated) :
		min_year(minYear), cargo_volume(cargoVolume), min_max_weight(minMaxWeight), refrigerated(refrigerated) {}
