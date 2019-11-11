#ifndef FEUP_AEDA_PROJ1_COMMERCIAL_PREFERENCE_H
#define FEUP_AEDA_PROJ1_COMMERCIAL_PREFERENCE_H


class CommercialPreference {
public:
	CommercialPreference(unsigned int minYear, float cargoVolume, float minMaxWeight, bool refrigerated);

private:
	unsigned min_year;

	float cargo_volume;

	float min_max_weight;

	bool refrigerated;
};


#endif //FEUP_AEDA_PROJ1_COMMERCIAL_PREFERENCE_H
