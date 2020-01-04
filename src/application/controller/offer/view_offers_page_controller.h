#ifndef FEUP_AEDA_PROJ1_VIEW_OFFERS_PAGE_CONTROLLER_H
#define FEUP_AEDA_PROJ1_VIEW_OFFERS_PAGE_CONTROLLER_H


#include "../../../auth/current_session/current_session.h"
#include "../../../model/company/company.h"
#include <vector>


class ViewOffersPageController {
public:
    ViewOffersPageController(CurrentSession &current_session, AuthUserManager &auth_user_manager, Company &company);

	vector<Offer> getOffers(int page, int max_per_page);

    int getPageCount(int max_per_page);

    Offer *getOffer(int current_page, const int MAX_PER_PAGE, int index);

private:
    CurrentSession &current_session;

    AuthUserManager &auth_user_manager;

    Company &company;
};


#endif //FEUP_AEDA_PROJ1_VIEW_OFFERS_PAGE_CONTROLLER_H
