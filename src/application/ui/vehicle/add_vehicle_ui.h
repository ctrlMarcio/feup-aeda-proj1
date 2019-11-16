#ifndef FEUP_AEDA_PROJ1_ADD_VEHICLE_UI_H
#define FEUP_AEDA_PROJ1_ADD_VEHICLE_UI_H


#include "../ui.h"
#include "../ui_manager.h"
#include "../../controller/vehicle/add_vehicle_controller.h"

class AddVehicleUI : public UI {
public:
	explicit AddVehicleUI(UIManager &ui_manager);

	void run() override;

private:
	AddVehicleController controller;

	void addPassengerVehicle();

	void addCommercialVehicle();
};


#endif //FEUP_AEDA_PROJ1_ADD_VEHICLE_UI_H
