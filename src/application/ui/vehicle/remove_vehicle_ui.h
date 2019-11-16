#ifndef FEUP_AEDA_PROJ1_REMOVE_VEHICLE_UI_H
#define FEUP_AEDA_PROJ1_REMOVE_VEHICLE_UI_H


#include "../../controller/vehicle/remove_vehicle_controller.h"
#include "../ui_manager.h"

class RemoveVehicleUI : public UI {
public:
	explicit RemoveVehicleUI(UIManager &ui_manager);

	void run() override;

private:
	RemoveVehicleController controller;

	void showAllVehicles() const;
};


#endif //FEUP_AEDA_PROJ1_REMOVE_VEHICLE_UI_H
