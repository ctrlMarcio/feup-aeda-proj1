#ifndef FEUP_AEDA_PROJ1_INVALID_VEHICLE_EXCEPTION_H
#define FEUP_AEDA_PROJ1_INVALID_VEHICLE_EXCEPTION_H


#include <stdexcept>

class InvalidVehicleException : public std::logic_error {
  public:
	InvalidVehicleException(const std::string &message = "The vehicle is invalid.");
};


#endif //FEUP_AEDA_PROJ1_INVALID_VEHICLE_EXCEPTION_H
