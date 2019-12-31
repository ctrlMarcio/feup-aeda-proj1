#include "add_maintenance_controller.h"

AddMaintenanceController::AddMaintenanceController(VehicleManager &vehicle_manager, VehicleList &vehicleList,
												   OfferManager &offerManager) :
		vehicle_manager(vehicle_manager),
		vehicle_list(vehicleList),
		offer_manager(offerManager) {}

vector<IVehicle *> AddMaintenanceController::getVehicles() {
	return vehicle_list.getVehicles();
}

bool AddMaintenanceController::hasMaintenanceDay(IVehicle &vehicle) {
	this->vehicle = &vehicle;
	return vehicle_manager.hasMaintenance(vehicle);
}

Date AddMaintenanceController::getMaintenanceDay() const {
	return vehicle_manager.getMaintenanceDay(*vehicle);
}

bool AddMaintenanceController::addMaintenanceDay(const Date &date) {
	bool valid = vehicle_manager.setMaintenanceDay(*vehicle, date);

	if (valid)
		offer_manager.removeDay(*vehicle, date);

	return valid;
}
