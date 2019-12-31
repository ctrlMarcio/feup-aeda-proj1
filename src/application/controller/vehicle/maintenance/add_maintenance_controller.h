#ifndef FEUP_AEDA_PROJ1_ADD_MAINTENANCE_CONTROLLER_H
#define FEUP_AEDA_PROJ1_ADD_MAINTENANCE_CONTROLLER_H


#include "../../../../model/vehicle/vehicle_manager.h"
#include "../../../../model/offer/offer_manager.h"

class AddMaintenanceController {
public:
	AddMaintenanceController(VehicleManager &vehicle_manager, VehicleList &vehicleList, OfferManager &offerManager);

	vector<IVehicle *> getVehicles();

	bool hasMaintenanceDay(IVehicle &vehicle);

	Date getMaintenanceDay() const;

	bool addMaintenanceDay(const Date &date);

private:
	VehicleManager &vehicle_manager;

	VehicleList &vehicle_list;

	OfferManager &offer_manager;

	IVehicle *vehicle = nullptr;
};


#endif //FEUP_AEDA_PROJ1_ADD_MAINTENANCE_CONTROLLER_H
