#include "i_vehicle.h"
#include "passenger_vehicle.h"
#include "commercial_vehicle.h"
#include <typeinfo>

IVehicle::~IVehicle() = default;

bool IVehicle::operator==(const IVehicle &vehicle) const {
	return this->getNumberPlate() == vehicle.getNumberPlate();
}

ostream &operator<<(ostream &ostream, const IVehicle &vehicle) {
	vehicle.print(ostream);
	return ostream;
}
