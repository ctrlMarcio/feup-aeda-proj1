#ifndef FEUP_AEDA_PROJ1_RENT_VEHICLE_CONTROLLER_H
#define FEUP_AEDA_PROJ1_RENT_VEHICLE_CONTROLLER_H


#include "../../../model/rental/rental_manager.h"
#include "../../../model/offer/offer.h"

class RentVehicleController {
public:
	RentVehicleController(RentalManager &rental_manager, Offer &offer, IRenter &renter);

	Offer &getOffer();

	Rental createRental(Date begin, Date end);

	bool confirm(Rental rental);

private:
	RentalManager &rental_manager;

	Offer &offer;

	IRenter &renter;
};


#endif //FEUP_AEDA_PROJ1_RENT_VEHICLE_CONTROLLER_H
