#include "rental_manager.h"

Rental RentalManager::createRental(Offer &offer, const Schedule &schedule) {
	return Rental{offer, schedule};
}

bool RentalManager::isValid(Rental rental) {
	// TODO
	return true;
}

bool RentalManager::add(Rental rental) {
	if (!isValid(rental))
		return false;

	rentals.push_back(rental);
	return true;
}

const std::list<Rental> &RentalManager::getAllRentals() const {
	return rentals;
}
