#ifndef FEUP_AEDA_PROJ1_NON_EXISTENT_VEHICLE_EXCEPTION_H
#define FEUP_AEDA_PROJ1_NON_EXISTENT_VEHICLE_EXCEPTION_H


#include <stdexcept>

class NonExistentVehicleException : std::logic_error {
public:
	explicit NonExistentVehicleException(const std::string &number_plate, const std::string &message = "The vehicle does not exist.");

private:
	const std::string &number_plate;

	const std::string &message;
};


#endif //FEUP_AEDA_PROJ1_NON_EXISTENT_VEHICLE_EXCEPTION_H
