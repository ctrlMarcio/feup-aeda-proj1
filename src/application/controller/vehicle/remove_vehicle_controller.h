#ifndef FEUP_AEDA_PROJ1_REMOVE_VEHICLE_CONTROLLER_H
#define FEUP_AEDA_PROJ1_REMOVE_VEHICLE_CONTROLLER_H


#include "../../../model/vehicle/vehicle_list.h"

class RemoveVehicleController {
public:
	explicit RemoveVehicleController(VehicleList &vehicle_list);

	VehicleList &getVehicleList() const;

	void remove(IVehicle &vehicle);

private:
	VehicleList &vehicle_list;
};


#endif //FEUP_AEDA_PROJ1_REMOVE_VEHICLE_CONTROLLER_H
