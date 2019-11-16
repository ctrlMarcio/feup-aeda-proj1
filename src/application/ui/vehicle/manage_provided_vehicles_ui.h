#ifndef FEUP_AEDA_PROJ1_MANAGE_PROVIDED_VEHICLES_UI_H
#define FEUP_AEDA_PROJ1_MANAGE_PROVIDED_VEHICLES_UI_H


#include "../../controller/vehicle/manage_provided_vehicles_controller.h"
#include "../ui.h"

class ManageProvidedVehiclesUI : public UI {
public:
	explicit ManageProvidedVehiclesUI(UIManager &ui_manager);

	void run() override;

private:
	ManageProvidedVehiclesController controller;

	static char getOption();

	void showVehicles() const;
};


#endif //FEUP_AEDA_PROJ1_MANAGE_PROVIDED_VEHICLES_UI_H
