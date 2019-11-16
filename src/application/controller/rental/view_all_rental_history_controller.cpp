#include "view_all_rental_history_controller.h"

ViewAllRentalHistoryController::ViewAllRentalHistoryController(RentalManager &rental_manager) :
		rental_manager(rental_manager) {}

const std::list<Rental> &ViewAllRentalHistoryController::getAllRentals() const {
	return rental_manager.getAllRentals();
}
