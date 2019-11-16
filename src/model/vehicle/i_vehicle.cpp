#include "i_vehicle.h"
#include <typeinfo>

IVehicle::~IVehicle() = default;

bool IVehicle::operator==(const IVehicle &vehicle) const {
	return typeid(*this) == typeid(vehicle) && isEqual(vehicle);
}

ostream &operator<<(ostream &ostream, const IVehicle &vehicle) {
	vehicle.print(ostream);
	return ostream;
}
