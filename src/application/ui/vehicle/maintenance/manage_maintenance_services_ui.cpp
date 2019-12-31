#include "manage_maintenance_services_ui.h"
#include "../../../../util/io_util.h"

ManageMaintenanceServicesUI::ManageMaintenanceServicesUI(UIManager &ui_manager) :
		controller(ui_manager.getCompany().getVehicleManager(),
				   ui_manager.getCompany().getOfferManager()) {}

void ManageMaintenanceServicesUI::run() {
	cout << endl;
	unsigned vehicle_amount = io_util::askUnsigned("How many vehicles do you wish to see?");
	vector<MaintainedVehicle> vehicles_to_see = controller.getVehicles(vehicle_amount);

	printVehicles(vehicles_to_see);

	bool valid;

	do {
		valid = true;
		int vehicle = io_util::askInt("Choose a vehicle to change the maintenance day of. (-1 to return)");

		if (vehicle == -1)
			return;

		try {
			controller.setVehicle(&vehicles_to_see.at(vehicle - 1));
		} catch (std::out_of_range &e) {
			valid = false;
		}
	} while (!valid);

	bool insert_maintenance_day = io_util::askBool("Do you want to change its maintenance day? (-1 to return)");

	if (!insert_maintenance_day)
		return;

	Date maintenance_day = io_util::askDate("Insert the new maintenance day.");
	if (!controller.changeMaintenanceDay(maintenance_day)) {
		cout << "Invalid date, aborting ..." << endl;
		return;
	}

	cout << endl << "Date change successfully!" << endl;
}

void ManageMaintenanceServicesUI::printVehicles(const vector<MaintainedVehicle> &to_print) const {
	int i = 1;
	for (const MaintainedVehicle &mv : to_print) {
		cout << endl << to_string(i++) + "." << endl;
		cout << mv.getVehicle();

		cout << "Maintenance date: ";

		Date date = mv.getMaintenanceDay();
		cout << date.getDay() << "/" << date.getMonth() << "/" << date.getYear() << endl;
	}
	cout << endl;
}
