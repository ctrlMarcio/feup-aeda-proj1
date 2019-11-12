#include "non_existent_vehicle_exception.h"

NonExistentVehicleException::NonExistentVehicleException(const std::string &number_plate, const std::string &message) :
		std::logic_error(message), number_plate(number_plate), message(message) {}
