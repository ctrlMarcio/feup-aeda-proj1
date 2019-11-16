#include "view_recommended_offers_controller.h"

ViewRecommendedOffersController::ViewRecommendedOffersController(PreferenceList &preference_list,
																 OfferManager &offer_manager) :
		preference_list(preference_list), offer_manager(offer_manager) {}

vector<Offer *> ViewRecommendedOffersController::getRecommendedOffers() {
	this->offers = offer_manager.getRecommendedOffers(preference_list);
	return offers;
}

vector<Offer *> ViewRecommendedOffersController::getOffers(int page, int max_per_page) {
	vector<Offer *> result;
	int first_index = (page - 1) * max_per_page;
	for (int i = 0; i < max_per_page; i++) {
		int index = first_index + i;
		if (index >= offers.size()) break;
		result.push_back(offers[index]);
	}
	return result;
}

int ViewRecommendedOffersController::getPageCount(int max_per_page) {
	int size = offers.size();
	return size / max_per_page + (size % max_per_page == 0 ? 0 : 1);
}

Offer *ViewRecommendedOffersController::getOffer(int current_page, const int MAX_PER_PAGE, int index) {
	return getOffers(current_page, MAX_PER_PAGE)[index];
}
