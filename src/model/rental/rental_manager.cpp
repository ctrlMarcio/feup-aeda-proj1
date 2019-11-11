#include "rental_manager.h"

Rental RentalManager::createRental(Offer &offer, const Schedule &schedule) {
	return Rental{offer, schedule};
}

Rental RentalManager::createRental(Offer &offer, const Date &begin, const Date &end) {
	return Rental{offer, begin, end};
}

bool RentalManager::isValid(const Rental &rental) {
	return (rental.getOffer().hasSchedule(rental.getSchedule()));
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
