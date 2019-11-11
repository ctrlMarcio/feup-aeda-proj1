#include "i_vehicle.h"
#include <typeinfo>

bool IVehicle::operator==(const IVehicle &vehicle) const {
	return typeid(*this) == typeid(vehicle) && isEqual(vehicle);
}
