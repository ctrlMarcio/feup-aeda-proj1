#include "add_maintenance_ui.h"
#include "../../../../util/io_util.h"

AddMaintenanceUI::AddMaintenanceUI(UIManager &ui_manager) :
		controller(ui_manager.getCompany().getVehicleManager(),
				   ui_manager.getCompany().getVehicleManager().getVehicleList(),
				   ui_manager.getCompany().getOfferManager()) {}

void AddMaintenanceUI::run() {
	vector<IVehicle *> vehicles = controller.getVehicles();

	showAllVehicles(vehicles);
	IVehicle *chosen = getVehicle(vehicles);

	if (!chosen)
		return;

	bool has_maintenance = controller.hasMaintenanceDay(*chosen);


	if (has_maintenance) {
		Date maintenance_day = controller.getMaintenanceDay();

		cout << "The vehicle already has a scheduled maintenance day: " << maintenance_day.getDay() << "/"
			 << maintenance_day.getMonth() << "/" << maintenance_day.getYear() << endl;
		bool change = io_util::askBool("Do you want to change it anyway?");

		if (!change) {
			cout << "OK, returning ..." << endl;
			return;
		}
	}

	bool valid;
	do {
		Date new_day = io_util::askDate("When will the vehicle attend to the maintenance services?");
		valid = controller.addMaintenanceDay(new_day);
		if (!valid) {
			bool returning = io_util::askBool("Date invalid, return?");
			if (returning)
				return;
		}
	} while (!valid);

}

IVehicle *AddMaintenanceUI::getVehicle(vector<IVehicle *> &vehicles) const {
	int i = io_util::askInt("Choose a vehicle. (-1 to return) ");
	IVehicle *chosen = nullptr;

	bool valid;
	do {
		valid = true;
		if (i == -1)
			return chosen;

		try {
			chosen = vehicles[i - 1];
		} catch (out_of_range &e) {
			valid = false;
			i = io_util::askInt("Invalid vehicle, please choose a vehicle. (-1 to return) ");
		}
	} while (!valid);

	return chosen;
}

void AddMaintenanceUI::showAllVehicles(vector<IVehicle *> &vehicles) const {
	for (unsigned long i = 0; i < vehicles.size(); ++i) {
		cout << i + 1 << "." << endl;
		cout << *vehicles.at(i);
		cout << endl;
	}
}
