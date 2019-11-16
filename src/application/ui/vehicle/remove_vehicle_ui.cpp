#include "remove_vehicle_ui.h"
#include "../../../util/io_util.h"

RemoveVehicleUI::RemoveVehicleUI(UIManager &ui_manager) : controller(ui_manager.getCompany().getUserManager().getProvider(
		ui_manager.getCurrentSession().getUser().getIdentificationNumber()
)->getVehicleList()) {}

void RemoveVehicleUI::run() {
	showAllVehicles();
	int to_remove = io_util::askInt("Choose a vehicle. (0 to return)");

	if (to_remove == 0)
		return;

	if (to_remove > controller.getVehicleList().getVehicles().size() || to_remove < 0) {
		cout << "The vehicle does not exist. Try again..." << endl;
		run();
	}

	controller.remove(*controller.getVehicleList().getVehicles()[to_remove - 1]);
	cout << "Vehicle removed!" << endl;
}

void RemoveVehicleUI::showAllVehicles() const {
	cout << endl << "=== Vehicles ===" << endl << endl;

	const vector<IVehicle *> &vehicles = controller.getVehicleList().getVehicles();
	for (size_t i = 0; i < vehicles.size(); ++i) {
		cout << i + 1 << ")" << endl << *vehicles[i] << endl;
	}
}
