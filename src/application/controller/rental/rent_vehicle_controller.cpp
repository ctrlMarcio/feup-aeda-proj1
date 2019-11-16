#include "rent_vehicle_controller.h"

RentVehicleController::RentVehicleController(RentalManager &rental_manager, Offer &offer, IRenter &renter) :
		rental_manager(rental_manager), offer(offer), renter(renter) {}

Offer &RentVehicleController::getOffer() {
	return offer;
}

Rental RentVehicleController::createRental(Date begin, Date end) {
	return RentalManager::build(offer, begin, end, renter);
}

bool RentVehicleController::confirm(Rental rental) {
	bool valid = rental_manager.add(rental);
	if (valid)
		offer.removeScheduleAvailability(rental.getSchedule());
	return valid;
}
