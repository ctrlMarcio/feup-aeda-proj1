#include <list>
#include "vehicle_manager.h"
#include "../../application/io/file_handling.h"
#include "../../exception/invalid_file_exception.h"
#include "../../util/string_util.h"
#include "../../exception/non_existent_vehicle_exception.h"

const VehicleList &VehicleManager::getVehicleList() const {
	return vehicle_list;
}

VehicleList &VehicleManager::getVehicleList() {
	return vehicle_list;
}

void VehicleManager::read(const std::string &directory) {
	std::string file_path = directory + "/" + file_handling::company_vehicle;

	ifstream ifstream;
	ifstream.open(file_path);

	if (!ifstream.is_open())
		throw InvalidFileException(file_path);


	std::string line;
	while (getline(ifstream, line)) {
		std::vector<std::string> params = string_util::split(line, file_handling::delimiter);
		this->vehicle_list.read(params, 0);
	}
}

void VehicleManager::write(const std::string &directory) {
	std::string file_path = directory + "/" + file_handling::company_vehicle;

	ofstream ofstream;
	ofstream.open(file_path);

	if (!ofstream.is_open())
		throw InvalidFileException(file_path);

	for (const IVehicle *vehicle : vehicle_list.getVehicles()) {
		vehicle->printToFile(ofstream);
		ofstream << endl;
	}
	ofstream << std::endl;
}

vector<MaintainedVehicle> VehicleManager::getMaintainedVehicles(size_t amount) {
	vector<MaintainedVehicle> res;

	for (size_t count = 0; count < amount && !maintained_vehicles.empty(); count++) {
		MaintainedVehicle vehicle = maintained_vehicles.top();
		maintained_vehicles.pop();
		res.push_back(vehicle);
		count++;
	}

	for (MaintainedVehicle mv : res)
		maintained_vehicles.push(mv);

	return res;
}

void VehicleManager::setMaintenanceDay(MaintainedVehicle &maintained_vehicle, const Date &day) {
	if (!hasMaintainedVehicle(maintained_vehicle)) {
		// adds the vehicle if it does not exist
		maintained_vehicle.setMaintenanceDay(day);
		maintained_vehicles.push(maintained_vehicle);
		return;
	}

	list<MaintainedVehicle> aux;

	while (!maintained_vehicles.empty()) {
		MaintainedVehicle mv = maintained_vehicles.top();
		maintained_vehicles.pop();

		if (mv == maintained_vehicle)
			break;

		aux.push_back(mv);
	}

	bool valid = maintained_vehicle.setMaintenanceDay(day);
	maintained_vehicles.push(maintained_vehicle);

	for (MaintainedVehicle vehicle : aux)
		maintained_vehicles.push(vehicle);
}

bool VehicleManager::hasMaintainedVehicle(const MaintainedVehicle &vehicle) {
	bool has = false;
	list<MaintainedVehicle> aux;

	while (!maintained_vehicles.empty() && !has) {
		MaintainedVehicle mv = maintained_vehicles.top();
		aux.push_back(mv);
		maintained_vehicles.pop();

		if (mv == vehicle)
			has = true;
	}

	for (MaintainedVehicle i : aux)
		maintained_vehicles.push(i);

	return has;
}

bool VehicleManager::addMaintainedVehicle(const MaintainedVehicle &maintained_vehicle) {
	if (hasMaintainedVehicle(maintained_vehicle))
		return false;

	maintained_vehicles.push(maintained_vehicle);
	return true;
}

bool VehicleManager::hasMaintenance(const IVehicle &vehicle) {
	bool found = false;
	list<MaintainedVehicle> aux;

	while (!maintained_vehicles.empty()) {
		MaintainedVehicle top = maintained_vehicles.top();

		if (top.getVehicle() == vehicle) {
			found = true;
			break;
		}

		maintained_vehicles.pop();
		aux.push_back(top);
	}

	for (MaintainedVehicle mv : aux)
		maintained_vehicles.push(mv);

	return found;
}

Date VehicleManager::getMaintenanceDay(const IVehicle &vehicle) {
	list<MaintainedVehicle> aux;
	Date res;

	while (!maintained_vehicles.empty()) {
		MaintainedVehicle top = maintained_vehicles.top();

		if (top.getVehicle() == vehicle) {
			res = top.getMaintenanceDay();
			break;
		}

		maintained_vehicles.pop();
		aux.push_back(top);
	}

	// verifies if the vehicle was found
	bool empty = false;
	if (maintained_vehicles.empty())
		empty = true;

	for (MaintainedVehicle mv : aux)
		maintained_vehicles.push(mv);

	if (empty)
		throw NonExistentVehicleException(vehicle.getNumberPlate(), "The vehicle has no maintenance scheduled");

	return res;
}

void VehicleManager::setMaintenanceDay(IVehicle &vehicle, const Date &date) {
	MaintainedVehicle maintained_vehicle(vehicle, date);
	setMaintenanceDay(maintained_vehicle, date);
}
