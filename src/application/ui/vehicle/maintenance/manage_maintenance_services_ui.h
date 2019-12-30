#ifndef FEUP_AEDA_PROJ1_MANAGE_MAINTENANCE_SERVICES_UI_H
#define FEUP_AEDA_PROJ1_MANAGE_MAINTENANCE_SERVICES_UI_H


#include "../../ui.h"
#include "../../ui_manager.h"
#include "../../../controller/vehicle/maintenance/manage_maintenance_services_controller.h"

class ManageMaintenanceServicesUI : public UI {
public:
	explicit ManageMaintenanceServicesUI(UIManager &ui_manager);

	void run() override;

private:
	ManageMaintenanceServicesController controller;

	void printVehicles(const vector<MaintainedVehicle> &to_print) const;
};


#endif //FEUP_AEDA_PROJ1_MANAGE_MAINTENANCE_SERVICES_UI_H
