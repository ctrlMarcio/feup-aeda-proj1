#include "manage_maintenance_services_controller.h"

ManageMaintenanceServicesController::ManageMaintenanceServicesController(VehicleManager &vehicleManager,
																		 OfferManager &offerManager) :
		vehicle_manager(vehicleManager), offer_manager(offerManager) {}

vector<MaintainedVehicle *> ManageMaintenanceServicesController::getVehicles(unsigned vehicle_amount) const {
	return vehicle_manager.getMaintainedVehicles(vehicle_amount);
}

void ManageMaintenanceServicesController::setVehicle(MaintainedVehicle *vehicle) {
	ManageMaintenanceServicesController::vehicle = vehicle;
}

bool ManageMaintenanceServicesController::changeMaintenanceDay(const Date &maintenance_day) const {
	bool done = vehicle_manager.setMaintenanceDay(*vehicle, maintenance_day);

	if (done)
		offer_manager.removeDay(vehicle->getVehicle(), maintenance_day);

	return done;
}
