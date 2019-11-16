#include "view_rental_history_page_controller.h"

ViewRentalHistoryPageController::ViewRentalHistoryPageController(RentalManager &rental_manager) : rental_manager(
        rental_manager) {}

int ViewRentalHistoryPageController::getPageCount(const string &identification_number, int MAX_PER_PAGE) {
    int size = rental_manager.getRentals(identification_number).size();
    return size / MAX_PER_PAGE + (size % MAX_PER_PAGE == 0 ? 0 : 1);
}

vector<Rental *> ViewRentalHistoryPageController::getRentals(const string &identification_number, int current_page,
                                                             const int MAX_PER_PAGE) {
    vector<Rental *> result;
    int first_index = (current_page - 1) * MAX_PER_PAGE;
    vector<Rental *> rentals = rental_manager.getRentals(identification_number);
    for (int i = 0; i < MAX_PER_PAGE; i++) {
        int index = first_index + i;
        if (index >= rentals.size()) break;
        result.push_back(rentals[index]);
    }
    return result;
}
