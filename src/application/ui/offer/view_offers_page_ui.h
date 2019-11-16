#ifndef FEUP_AEDA_PROJ1_VIEW_OFFERS_PAGE_UI_H
#define FEUP_AEDA_PROJ1_VIEW_OFFERS_PAGE_UI_H


#include "../ui.h"
#include "../ui_manager.h"
#include "../../controller/offer/view_offers_page_controller.h"

class ViewOffersPageUI : public UI {
public:
    explicit ViewOffersPageUI(UIManager &ui_manager);

    void run() override;

private:
    static const int MAX_PER_PAGE = 8;

    UIManager &ui_manager;

    ViewOffersPageController controller;

    string offers();

    string getOffer();

    string singleOffer(Offer &offer);

    int current_page = 1;

    void increasePage();

    void decreasePage();

    void selectOffer(Offer &offer);
};


#endif //FEUP_AEDA_PROJ1_VIEW_OFFERS_PAGE_UI_H
