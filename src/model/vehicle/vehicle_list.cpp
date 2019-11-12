#include "vehicle_list.h"
#include "passenger_vehicle.h"
#include "commercial_vehicle.h"

VehicleList::~VehicleList() {
	for (IVehicle *v : vehicles)
		delete v;
	vehicles.clear();
}

IVehicle &VehicleList::createVehicle(const std::string &number_plate, const std::string &brand, const std::string &model,
									 unsigned year, unsigned seat_number) const {
	IVehicle *vehicle = new PassengerVehicle(number_plate, brand, model, year, seat_number);
	return *vehicle;
}

IVehicle &VehicleList::createVehicle(const std::string &number_plate, const std::string &brand, const std::string &model,
									 unsigned year, double cargo_volume, double max_weight, bool is_refrigerated) const {
	IVehicle *vehicle = new CommercialVehicle(number_plate, brand, model, year, cargo_volume, max_weight, is_refrigerated);
	return *vehicle;
}

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

bool VehicleList::operator==(const VehicleList &rhs) const {
    return vehicles == rhs.vehicles;
}

bool VehicleList::operator!=(const VehicleList &rhs) const {
    return !(rhs == *this);
}
