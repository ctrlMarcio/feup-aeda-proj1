#ifndef FEUP_AEDA_PROJ1_VIEW_RENTAL_HISTORY_PAGE_CONTROLLER_H
#define FEUP_AEDA_PROJ1_VIEW_RENTAL_HISTORY_PAGE_CONTROLLER_H


#include "../../../model/rental/rental_manager.h"

class ViewRentalHistoryPageController {
public:
    explicit ViewRentalHistoryPageController(RentalManager &rental_manager);

    int getPageCount(const int MAX_PER_PAGE);

    vector<Rental *> getRentals(const string &identification_number, int current_page, const int MAX_PER_PAGE);

private:
    RentalManager &rental_manager;
};


#endif //FEUP_AEDA_PROJ1_VIEW_RENTAL_HISTORY_PAGE_CONTROLLER_H
