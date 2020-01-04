#include "view_offers_page_controller.h"

ViewOffersPageController::ViewOffersPageController(CurrentSession &current_session, AuthUserManager &auth_user_manager,
                                                   Company &company) : current_session(current_session),
                                                                       auth_user_manager(auth_user_manager),
                                                                       company(company) {}

vector<Offer> ViewOffersPageController::getOffers(int page, int max_per_page) {
	vector<Offer> result;
    int first_index = (page - 1) * max_per_page;
    for (int i = 0; i < max_per_page; i++) {
        int index = first_index + i;
		if (index >= company.getOfferManager().getPossibleOffers().size()) break;
		result.push_back(company.getOfferManager().getPossibleOffers()[index]);
    }
    return result;
}

int ViewOffersPageController::getPageCount(int max_per_page) {
	int size = company.getOfferManager().getPossibleOffers().size();
    return size / max_per_page + (size % max_per_page == 0 ? 0 : 1);
}

Offer *ViewOffersPageController::getOffer(int current_page, const int MAX_PER_PAGE, int index) {
	return &getOffers(current_page, MAX_PER_PAGE)[index];
}
