#include "vehicle_list.h"

VehicleList::~VehicleList() {
	for (IVehicle *v : vehicles)
		delete v;
	vehicles.clear();
}

/* TODO create passenger vehicle using new to return the reference
IVehicle &VehicleList::createVehicle(unsigned seat_number) const {
}*/

/* TODO create commercial vehicle using new to return the reference
IVehicle &VehicleList::createVehicle(double cargo_volume, double max_weight, bool is_refrigerated) const {
}*/

bool VehicleList::add(IVehicle *vehicle) {
	if (isValid(*vehicle)) {
		vehicles.push_back(vehicle);
		return true;
	} else {
		return false;
	}
}

bool VehicleList::isValid(const IVehicle &vehicle) const {
	return !this->has(vehicle);
}

bool VehicleList::remove(const IVehicle &vehicle) {
	bool removed = false;

	for (auto it = vehicles.begin(); it != vehicles.end(); ++it) {
		if (*(*it) == vehicle) {
			vehicles.erase(it);
			removed = true;
			break;
		}
	}

	return removed;
}

const vector<IVehicle *> &VehicleList::getVehicles() const {
	return vehicles;
}

bool VehicleList::has(const IVehicle &vehicle) const {
	for (IVehicle *listed_vehicle : vehicles)
		if (*listed_vehicle == vehicle)
			return true;
	return false;
}
