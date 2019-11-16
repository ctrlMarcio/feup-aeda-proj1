#include "manage_provided_vehicles_controller.h"
#include "../../ui/vehicle/add_vehicle_ui.h"

ManageProvidedVehiclesController::ManageProvidedVehiclesController(UIManager &ui_manager) :
		ui_manager(ui_manager) {}

void ManageProvidedVehiclesController::addVehicle() {
	ui_manager.setCurrent(new AddVehicleUI(ui_manager));
	ui_manager.run();
}

const std::vector<IVehicle *> &ManageProvidedVehiclesController::getVehicles() const {
	string id = ui_manager.getCurrentSession().getUser().getIdentificationNumber();
	IProvider *provider = ui_manager.getCompany().getUserManager().getProvider(id);
	return provider->getVehicleList().getVehicles();
}
