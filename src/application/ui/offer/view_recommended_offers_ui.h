#ifndef FEUP_AEDA_PROJ1_VIEW_RECOMMENDED_OFFERS_UI_H
#define FEUP_AEDA_PROJ1_VIEW_RECOMMENDED_OFFERS_UI_H


#include "../ui.h"
#include "../ui_manager.h"
#include "../../controller/offer/view_recommended_offers_controller.h"

class ViewRecommendedOffersUI : public UI {
public:
	explicit ViewRecommendedOffersUI(UIManager &ui_manager);

	void run() override;

private:
	static const int MAX_PER_PAGE = 8;

	ViewRecommendedOffersController controller;

	int current_page = 1;

	UIManager &ui_manager;

	std::string offers();

	string singleOffer(Offer &offer);

	char getOffer();

	void selectOffer(Offer &offer);

	void increasePage();

	void decreasePage();
};


#endif //FEUP_AEDA_PROJ1_VIEW_RECOMMENDED_OFFERS_UI_H
