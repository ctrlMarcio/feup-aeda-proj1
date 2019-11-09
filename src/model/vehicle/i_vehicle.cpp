#include "i_vehicle.h"

bool IVehicle::operator==(const IVehicle &vehicle) const {
	// If the subclasses are the same, then compares them
	return typeid(*this) == typeid(vehicle) && isEqual(vehicle);
}
