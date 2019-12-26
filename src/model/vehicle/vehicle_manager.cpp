#include <list>
#include "vehicle_manager.h"
#include "../../application/io/file_handling.h"
#include "../../exception/invalid_file_exception.h"
#include "../../util/string_util.h"

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

bool VehicleManager::setMaintenanceDay(MaintainedVehicle &maintained_vehicle, const Date &day) {
	if (!hasMaintainedVehicle(maintained_vehicle))
		return false;

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

	return valid;
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
