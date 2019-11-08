#ifndef FEUP_AEDA_PROJ1_OFFER_MANAGER_H
#define FEUP_AEDA_PROJ1_OFFER_MANAGER_H


#include <vector>
#include "offer.h"
#include "../preference/preference.h"


using namespace std;

class OfferManager {
public:
	vector<Offer *> getRecommendedOffers(const std::list<Preference> &preferences) const;

    vector<Offer> &getOffers();

private:
	vector<Offer> offers;
};


#endif //FEUP_AEDA_PROJ1_OFFER_MANAGER_H
