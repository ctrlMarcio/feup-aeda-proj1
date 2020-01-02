#include "rent_vehicle_controller.h"
#include "../../../model/contract/contract_manager.h"

RentVehicleController::RentVehicleController(RentalManager &rental_manager, Offer &offer, IRenter &renter,
                                             ContractManager &contract_manager) :
		rental_manager(rental_manager), offer(offer), renter(renter), contract_manager(contract_manager) {}

Offer &RentVehicleController::getOffer() {
	return offer;
}

Rental RentVehicleController::createRental(Date begin, Date end) {
	return RentalManager::build(offer, begin, end, renter);
}

bool RentVehicleController::confirm(Rental rental) {
    RentalContract *contract = ContractManager::build(&renter, rental);
	bool valid = rental_manager.add(rental) && contract_manager.add(contract);
	if (valid)
		offer.removeScheduleAvailability(rental.getSchedule());
	return valid;
}

bool RentVehicleController::isValid(Rental rental) {
	return rental_manager.isValid(rental);
}
