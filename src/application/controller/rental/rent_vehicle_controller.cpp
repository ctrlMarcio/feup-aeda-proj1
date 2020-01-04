#include "rent_vehicle_controller.h"
#include "../../../model/contract/contract_manager.h"

RentVehicleController::RentVehicleController(RentalManager &rental_manager, Offer &offer, IRenter &renter,
											 ContractManager &contract_manager, ClientManager &client_manager) :
		rental_manager(rental_manager), offer(offer), renter(renter), contract_manager(contract_manager),
		client_manager(client_manager) {}

Offer &RentVehicleController::getOffer() {
	return offer;
}

Rental RentVehicleController::createRental(Date begin, Date end) {
	return RentalManager::build(offer, begin, end, renter);
}

bool RentVehicleController::confirm(Rental rental) {
	bool valid = rental_manager.add(rental);

	if (!valid)
		return false;

	RentalContract *contract = ContractManager::build(&renter, rental_manager.getAllRentals().back());
	valid = contract_manager.add(contract);

	if (valid) {
		offer.removeScheduleAvailability(rental.getSchedule());
		client_manager.update(contract_manager);
	}
	return valid;
}

bool RentVehicleController::isValid(Rental rental) {
	return rental_manager.isValid(rental);
}
