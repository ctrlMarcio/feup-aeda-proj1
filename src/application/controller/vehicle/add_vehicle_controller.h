#ifndef FEUP_AEDA_PROJ1_ADD_VEHICLE_CONTROLLER_H
#define FEUP_AEDA_PROJ1_ADD_VEHICLE_CONTROLLER_H


#include "../../../model/vehicle/vehicle_list.h"

class AddVehicleController {
public:
	explicit AddVehicleController(VehicleList &vehicle_list);

	void createVehicle(const std::string &number_plate, const std::string &brand, const std::string &model, unsigned year, unsigned seat_number);

	void createVehicle(const std::string &number_plate, const std::string &brand, const std::string &model, unsigned year,
					   double cargo_volume, double max_weight, bool refrigerated);

	bool isValid() const;

	IVehicle *getVehicle() const;

	bool confirm() const;

private:
	VehicleList &vehicle_list;

	IVehicle *vehicle = nullptr;
};


#endif //FEUP_AEDA_PROJ1_ADD_VEHICLE_CONTROLLER_H
