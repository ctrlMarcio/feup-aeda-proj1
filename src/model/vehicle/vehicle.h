#ifndef FEUP_AEDA_PROJ1_VEHICLE_H
#define FEUP_AEDA_PROJ1_VEHICLE_H


#include <ostream>

class Vehicle {
public:

	friend std::ostream &operator<<(std::ostream &ostream, const Vehicle &vehicle);
};


#endif //FEUP_AEDA_PROJ1_VEHICLE_H
