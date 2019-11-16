#ifndef FEUP_AEDA_PROJ1_VIEW_ALL_RENTAL_HISTORY_UI_H
#define FEUP_AEDA_PROJ1_VIEW_ALL_RENTAL_HISTORY_UI_H


#include "../ui_manager.h"
#include "../ui.h"
#include "../../controller/rental/view_all_rental_history_controller.h"

class ViewAllRentalHistoryUI : public UI {
public:
	explicit ViewAllRentalHistoryUI(UIManager &ui_manager);

	void run() override;

	void showRentals(const std::list<Rental> &rentals, int first, int qt) const;

private:
	ViewAllRentalHistoryController controller;
};


#endif //FEUP_AEDA_PROJ1_VIEW_ALL_RENTAL_HISTORY_UI_H
