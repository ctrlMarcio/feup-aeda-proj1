#include "rental_manager.h"

const std::list<Rental> &RentalManager::getAllRentals() const {
	return rentals;
}
