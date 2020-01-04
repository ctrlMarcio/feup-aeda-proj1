#include <list>
#include "vehicle_manager.h"
#include "../../application/io/file_handling.h"
#include "../../exception/invalid_file_exception.h"
#include "../../util/string_util.h"
#include "../../exception/non_existent_vehicle_exception.h"
#include "../../exception/invalid_date_exception.h"

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
		line = string_util::removeCarriageReturn(line);

		std::vector<std::string> params = string_util::split(line, file_handling::delimiter);
		unsigned first_element = 1;
		this->vehicle_list.read(params, first_element);

		vector<string> date = string_util::split(params[0], file_handling::time_delimiter);
		if (date.size() == 6) {
			Date maintenance_day(stoi(date[0]), stoi(date[1]), stoi(date[2]), stoi(date[3]), stoi(date[4]),
								 stoi(date[5]));

			setMaintenanceDay(vehicle_list.get(params[first_element + 1]), maintenance_day);
		}
	}
}

void VehicleManager::write(const std::string &directory) {
	std::string file_path = directory + "/" + file_handling::company_vehicle;

	ofstream ofstream;
	ofstream.open(file_path);

	if (!ofstream.is_open())
		throw InvalidFileException(file_path);

	for (const IVehicle *vehicle : vehicle_list.getVehicles()) {
		if (hasMaintenance(*vehicle))
			getMaintenanceDay(*vehicle).printToFile(ofstream);
		else
			ofstream << "null";

		ofstream << file_handling::delimiter;

		vehicle->printToFile(ofstream);
		ofstream << endl;
	}
	ofstream << std::endl;
}

vector<MaintainedVehicle> VehicleManager::getMaintainedVehicles(unsigned long amount) {
	vector<MaintainedVehicle> res;

	for (unsigned long count = 0; count < amount && !maintained_vehicles.empty(); count++) {
		MaintainedVehicle vehicle = *maintained_vehicles.top();
		res.push_back(vehicle);
		delete maintained_vehicles.top();
		maintained_vehicles.pop();
	}

	for (MaintainedVehicle &mv : res)
		maintained_vehicles.push(new MaintainedVehicle(mv));

	return res;
}

bool VehicleManager::setMaintenanceDay(MaintainedVehicle &maintained_vehicle, const Date &day) {
	auto *to_add = new MaintainedVehicle(maintained_vehicle);
	Date now;
	if (day <= now)
		return false;

	if (!hasMaintainedVehicle(*to_add)) {
		// adds the vehicle if it does not exist
		to_add->setMaintenanceDay(day);
		maintained_vehicles.push(to_add);
		return true;
	}

	list<MaintainedVehicle> aux;

	while (!maintained_vehicles.empty()) {
		MaintainedVehicle mv = *maintained_vehicles.top();
		delete maintained_vehicles.top();
		maintained_vehicles.pop();

		if (mv == *to_add)
			break;

		aux.push_back(mv);
	}

	to_add->setMaintenanceDay(day);
	maintained_vehicles.push(to_add);

	for (MaintainedVehicle &vehicle : aux)
		maintained_vehicles.push(new MaintainedVehicle(vehicle));

	return true;
}

bool VehicleManager::hasMaintainedVehicle(const MaintainedVehicle &vehicle) {
	bool has = false;
	list<MaintainedVehicle> aux;

	while (!maintained_vehicles.empty() && !has) {
		MaintainedVehicle mv = *maintained_vehicles.top();
		aux.push_back(mv);
		delete maintained_vehicles.top();
		maintained_vehicles.pop();

		if (mv == vehicle)
			has = true;
	}

	for (MaintainedVehicle &i : aux)
		maintained_vehicles.push(new MaintainedVehicle(i));

	return has;
}

bool VehicleManager::addMaintainedVehicle(const MaintainedVehicle &maintained_vehicle) {
	MaintainedVehicle *to_add = new MaintainedVehicle(maintained_vehicle);
	if (hasMaintainedVehicle(*to_add))
		return false;

	maintained_vehicles.push(to_add);
	return true;
}

bool VehicleManager::hasMaintenance(const IVehicle &vehicle) {
	bool found = false;
	list<MaintainedVehicle> aux;

	while (!maintained_vehicles.empty()) {
		MaintainedVehicle top = *maintained_vehicles.top();

		if (top.getVehicle() == vehicle) {
			found = true;
			break;
		}

		delete maintained_vehicles.top();
		maintained_vehicles.pop();
		aux.push_back(top);
	}

	for (MaintainedVehicle &mv : aux)
		maintained_vehicles.push(new MaintainedVehicle(mv));

	return found;
}

Date VehicleManager::getMaintenanceDay(const IVehicle &vehicle) {
	update();

	list<MaintainedVehicle> aux;
	Date res;

	while (!maintained_vehicles.empty()) {
		MaintainedVehicle top = *maintained_vehicles.top();

		if (top.getVehicle() == vehicle) {
			res = top.getMaintenanceDay();
			break;
		}

		delete maintained_vehicles.top();
		maintained_vehicles.pop();
		aux.push_back(top);
	}

	// verifies if the vehicle was found
	bool empty = false;
	if (maintained_vehicles.empty())
		empty = true;

	for (MaintainedVehicle &mv : aux)
		maintained_vehicles.push(new MaintainedVehicle(mv));

	if (empty)
		throw NonExistentVehicleException(vehicle.getNumberPlate(), "The vehicle has no maintenance scheduled");

	return res;
}

bool VehicleManager::setMaintenanceDay(IVehicle &vehicle, const Date &date) {
	try {
		MaintainedVehicle maintained_vehicle(vehicle, date);
		return setMaintenanceDay(maintained_vehicle, date);
	} catch (InvalidDateException &e) {
		return false;
	}
}

void VehicleManager::update() {
	Date now;

	while (!maintained_vehicles.empty() && maintained_vehicles.top()->getMaintenanceDay() < now)
		maintained_vehicles.pop();
}
