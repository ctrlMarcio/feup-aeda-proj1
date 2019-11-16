#include "remove_vehicle_controller.h"

RemoveVehicleController::RemoveVehicleController(VehicleList &vehicle_list) : vehicle_list(vehicle_list) {}

VehicleList &RemoveVehicleController::getVehicleList() const {
	return vehicle_list;
}

void RemoveVehicleController::remove(IVehicle &vehicle) {
	vehicle_list.remove(vehicle);
}
