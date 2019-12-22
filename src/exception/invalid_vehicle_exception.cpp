#include "invalid_vehicle_exception.h"

InvalidVehicleException::InvalidVehicleException(const std::string &message) : logic_error(message) {}
