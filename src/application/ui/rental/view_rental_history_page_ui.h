#ifndef FEUP_AEDA_PROJ1_VIEW_RENTAL_HISTORY_PAGE_UI_H
#define FEUP_AEDA_PROJ1_VIEW_RENTAL_HISTORY_PAGE_UI_H


#include "../ui.h"
#include "../ui_manager.h"
#include "../../controller/rental/view_rental_history_page_controller.h"

class ViewRentalHistoryPageUI : public UI {
public:
    explicit ViewRentalHistoryPageUI(UIManager &ui_manager);

    void run() override;

private:
    static const int MAX_PER_PAGE = 8;

    UIManager &ui_manager;

    ViewRentalHistoryPageController controller;

    char getOption();

    string rentals();

    int current_page = 1;

    void increasePage();

    void decreasePage();
};


#endif //FEUP_AEDA_PROJ1_VIEW_RENTAL_HISTORY_PAGE_UI_H
