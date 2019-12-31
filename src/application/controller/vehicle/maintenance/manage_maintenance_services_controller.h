#ifndef FEUP_AEDA_PROJ1_MANAGE_MAINTENANCE_SERVICES_CONTROLLER_H
#define FEUP_AEDA_PROJ1_MANAGE_MAINTENANCE_SERVICES_CONTROLLER_H


#include "../../../../model/vehicle/vehicle_manager.h"
#include "../../../../model/offer/offer_manager.h"

class ManageMaintenanceServicesController {
public:
	ManageMaintenanceServicesController(VehicleManager &vehicleManager, OfferManager &offerManager);

	vector<MaintainedVehicle *> getVehicles(unsigned vehicle_amount) const;

	void setVehicle(MaintainedVehicle *vehicle);

	bool changeMaintenanceDay(const Date &maintenance_day) const;

private:
	VehicleManager &vehicle_manager;

	OfferManager &offer_manager;

	MaintainedVehicle *vehicle;
};


#endif //FEUP_AEDA_PROJ1_MANAGE_MAINTENANCE_SERVICES_CONTROLLER_H
