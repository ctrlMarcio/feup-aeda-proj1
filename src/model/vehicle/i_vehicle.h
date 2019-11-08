#ifndef FEUP_AEDA_PROJ1_I_VEHICLE_H
#define FEUP_AEDA_PROJ1_I_VEHICLE_H


#include <ostream>

class IVehicle {
public:
	virtual IVehicle &operator=(const IVehicle &v) = 0;

	friend std::ostream &operator<<(std::ostream &ostream, const IVehicle &vehicle);
};


#endif //FEUP_AEDA_PROJ1_I_VEHICLE_H
