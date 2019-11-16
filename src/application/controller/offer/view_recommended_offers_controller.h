#ifndef FEUP_AEDA_PROJ1_VIEW_RECOMMENDED_OFFERS_CONTROLLER_H
#define FEUP_AEDA_PROJ1_VIEW_RECOMMENDED_OFFERS_CONTROLLER_H


#include <list>
#include "../../../model/offer/offer.h"
#include "../../../model/offer/offer_manager.h"

class ViewRecommendedOffersController {
public:
	ViewRecommendedOffersController(PreferenceList &preference_list, OfferManager &offer_manager);

	vector<Offer *> getRecommendedOffers();

	vector<Offer *> getOffers(int page, int max_per_page);

	int getPageCount(int max_per_page);

	Offer *getOffer(int current_page, int MAX_PER_PAGE, int index);

private:
	PreferenceList &preference_list;

	OfferManager &offer_manager;

	vector<Offer *> offers;
};


#endif //FEUP_AEDA_PROJ1_VIEW_RECOMMENDED_OFFERS_CONTROLLER_H
