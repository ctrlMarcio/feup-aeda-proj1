#ifndef FEUP_AEDA_PROJ1_COMMERCIAL_PREFERENCE_H
#define FEUP_AEDA_PROJ1_COMMERCIAL_PREFERENCE_H


#include <ostream>

class CommercialPreference {
public:
	CommercialPreference(unsigned int minYear, float cargoVolume, float minMaxWeight, bool refrigerated);

	unsigned int getMinYear() const;

	float getCargoVolume() const;

	float getMinMaxWeight() const;

	bool isRefrigerated() const;

	friend std::ostream &operator<<(std::ostream &ostream, const CommercialPreference &commercial_preference);

private:
	unsigned min_year;

	float cargo_volume;

	float min_max_weight;

	bool refrigerated;
};


#endif //FEUP_AEDA_PROJ1_COMMERCIAL_PREFERENCE_H
