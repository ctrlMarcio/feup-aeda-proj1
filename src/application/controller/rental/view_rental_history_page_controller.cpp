#include "view_rental_history_page_controller.h"

ViewRentalHistoryPageController::ViewRentalHistoryPageController(RentalManager &rental_manager) : rental_manager(
        rental_manager) {}

int ViewRentalHistoryPageController::getPageCount(const int MAX_PER_PAGE) {
    return 0;
}

vector<Rental *> ViewRentalHistoryPageController::getRentals(const string &identification_number, int current_page,
                                                             const int MAX_PER_PAGE) {
    return vector<Rental *>();
}
