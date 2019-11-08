#ifndef FEUP_AEDA_PROJ1_OFFER_MANAGER_H
#define FEUP_AEDA_PROJ1_OFFER_MANAGER_H


#include <vector>
#include "offer.h"
#include "../preference/preference.h"

class OfferManager {
public:
	std::vector<Offer *> getRecommendedOffers(const std::list<Preference> &preferences) const;

private:
	std::vector<Offer> offers;
};


#endif //FEUP_AEDA_PROJ1_OFFER_MANAGER_H
