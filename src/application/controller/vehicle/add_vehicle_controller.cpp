#include "add_vehicle_controller.h"

AddVehicleController::AddVehicleController(VehicleList &vehicle_list) : vehicle_list(vehicle_list) {}

void AddVehicleController::createVehicle(const std::string &number_plate, const std::string &brand, const std::string &model, unsigned year, unsigned seat_number) {
	this->vehicle = VehicleList::build(number_plate, brand, model, year, seat_number);
}

void AddVehicleController::createVehicle(const std::string &number_plate, const std::string &brand, const std::string &model, unsigned year,
										 double cargo_volume, double max_weight, bool refrigerated) {
	this->vehicle = VehicleList::build(number_plate, brand, model, year, cargo_volume, max_weight, refrigerated);
}

IVehicle *AddVehicleController::getVehicle() const {
	return vehicle;
}

bool AddVehicleController::isValid() const {
	return vehicle_list.isValid(*vehicle);
}

bool AddVehicleController::confirm() const {
	return vehicle_list.add(vehicle);
}

AddVehicleController::~AddVehicleController() {
	delete vehicle;
}
