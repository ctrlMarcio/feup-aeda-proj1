#ifndef FEUP_AEDA_PROJ1_ADD_MAINTENANCE_UI_H
#define FEUP_AEDA_PROJ1_ADD_MAINTENANCE_UI_H


#include "../../ui.h"
#include "../../../controller/vehicle/maintenance/add_maintenance_controller.h"
#include "../../ui_manager.h"

class AddMaintenanceUI : public UI {
public:
	explicit AddMaintenanceUI(UIManager &ui_manager);

	void run() override;

private:
	AddMaintenanceController controller;

	void showAllVehicles(vector<IVehicle *> &vehicles) const;

	IVehicle *getVehicle(vector<IVehicle *> &vehicles) const;
};


#endif //FEUP_AEDA_PROJ1_ADD_MAINTENANCE_UI_H
