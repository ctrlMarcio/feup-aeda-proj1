#ifndef FEUP_AEDA_PROJ1_EDIT_VEHICLE_CONTROLLER_H
#define FEUP_AEDA_PROJ1_EDIT_VEHICLE_CONTROLLER_H


#include "../../../model/vehicle/vehicle_list.h"
#include "../../../model/offer/offer_manager.h"

class EditVehicleController {
public:
	EditVehicleController(IProvider &provider, OfferManager &offer_manager);

	const vector<IVehicle *> &getVehicles() const;

	void setVehicle(IVehicle *vehicle);

	bool isUpToRent();

	bool createOffer(const std::list<Schedule> &schedules, float price);

	bool removeOffer();

	bool changePrice(float price);

	void setOffer();

	bool addSchedule(Schedule schedule);

private:
	VehicleList &vehicle_list;

	OfferManager &offer_manager;

	IProvider &provider;

	IVehicle *vehicle = nullptr;

	Offer *offer = nullptr;
};


#endif //FEUP_AEDA_PROJ1_EDIT_VEHICLE_CONTROLLER_H
