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
	std::string file_path = directory + file_handling::company_vehicle;

	ofstream ofstream;
	ofstream.open(file_path);

	if (!ofstream.is_open())
		throw InvalidFileException(file_path);

	for (const IVehicle *vehicle : vehicle_list.getVehicles()) {
		ofstream << file_handling::delimiter;
		vehicle->printToFile(ofstream);
	}
	ofstream << std::endl;
}
