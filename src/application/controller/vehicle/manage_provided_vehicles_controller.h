#ifndef FEUP_AEDA_PROJ1_MANAGE_PROVIDED_VEHICLES_CONTROLLER_H
#define FEUP_AEDA_PROJ1_MANAGE_PROVIDED_VEHICLES_CONTROLLER_H


#include "../../ui/ui_manager.h"

class ManageProvidedVehiclesController {
public:
	explicit ManageProvidedVehiclesController(UIManager &ui_manager);

	void addVehicle();

	void removeVehicle();

	void editVehicle();

	const std::vector<IVehicle *> &getVehicles() const;

private:
	UIManager &ui_manager;
};


#endif //FEUP_AEDA_PROJ1_MANAGE_PROVIDED_VEHICLES_CONTROLLER_H
