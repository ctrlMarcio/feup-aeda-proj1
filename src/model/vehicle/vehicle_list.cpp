#include "vehicle_list.h"
#include "passenger_vehicle.h"
#include "commercial_vehicle.h"
#include "../../exception/non_existent_vehicle_exception.h"
#include "../user/client.h"

IVehicle *VehicleList::build(const std::string &number_plate, const std::string &brand, const std::string &model,
							 unsigned year, unsigned seat_number) {
	return new PassengerVehicle(number_plate, brand, model, year, seat_number);
}

IVehicle *VehicleList::build(const std::string &number_plate, const std::string &brand, const std::string &model,
							 unsigned year, double cargo_volume, double max_weight, bool is_refrigerated) {
	return new CommercialVehicle(number_plate, brand, model, year, cargo_volume, max_weight,
								 is_refrigerated);
}

void VehicleList::read(const std::vector<std::string> &params, size_t first_element) {
	for (; first_element < params.size(); ++first_element) {
		if (params[first_element] == "passenger")
			first_element = readPassengerVehicle(params, first_element);
		else if (params[first_element] == "commercial")
			first_element = readCommercialVehicle(params, first_element);
		else
			break;
	}
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
			IVehicle *v = *it;
			vehicles.erase(it);
			delete v;
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

IVehicle &VehicleList::get(const std::string &number_plate) {
	for (IVehicle *vehicle : vehicles)
		if (vehicle->getNumberPlate() == number_plate)
			return *vehicle;

	throw NonExistentVehicleException(number_plate);
}

bool VehicleList::operator==(const VehicleList &rhs) const {
	return vehicles == rhs.vehicles;
}

bool VehicleList::operator!=(const VehicleList &rhs) const {
	return !(rhs == *this);
}

size_t VehicleList::readPassengerVehicle(const vector<std::string> &params, size_t i) {
	string number_plate = params[++i];
	string brand = params[++i];
	string model = params[++i];
	unsigned year = stoul(params[++i]);
	unsigned seat_number = stoul(params[++i]);

	this->add(build(number_plate, brand, model, year, seat_number));
	return i;
}

size_t VehicleList::readCommercialVehicle(const vector<std::string> &params, size_t i) {
	string number_plate = params[++i];
	string brand = params[++i];
	string model = params[++i];
	unsigned year = stoul(params[++i]);
	float cargo_volume = stof(params[++i]);
	float min_max_weight = stof(params[++i]);
	++i;
	bool refrigerated =
			params[i] == "y" || params[i] == "yes" || params[i] == "1" || params[i] == "t" || params[i] == "true";


	this->add(build(number_plate, brand, model, year, cargo_volume, min_max_weight, refrigerated));
	return i;
}
