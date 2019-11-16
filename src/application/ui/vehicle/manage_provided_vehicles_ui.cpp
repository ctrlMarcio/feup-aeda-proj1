#include "manage_provided_vehicles_ui.h"
#include "../../../util/date.h"
#include <sstream>
#include <iostream>

using namespace std;

ManageProvidedVehiclesUI::ManageProvidedVehiclesUI(UIManager &ui_manager) : controller(ui_manager) {}

void ManageProvidedVehiclesUI::run() {
	char option = 0;

	do {
		option = getOption();
		switch (option) {
			case '1':
				showVehicles();
				break;
			case '2':
				controller.addVehicle();
				break;
			case '3':
				controller.removeVehicle();
				break;
			case '4':
				//TODO controller.editVehicle();
				break;
			case '0':
				cout << endl << "Returning ..." << endl;
				break;
			default:
				cout << endl << "Invalid option, try again..." << endl;
				break;
		}
	} while (option != '0');
}

char ManageProvidedVehiclesUI::getOption() {
	stringstream options_stream;

	options_stream << endl;
	options_stream << "1 - View vehicles" << endl;
	options_stream << endl;
	options_stream << "2 - Add vehicle" << endl;
	options_stream << "3 - Remove vehicle" << endl;
	options_stream << "4 - Edit vehicle preferences" << endl;
	options_stream << endl;
	options_stream << "0 - Return" << endl;

	cout << options_stream.str();

	string option;

	cout << endl << "Option: ";

	getline(cin, option);

	return option[0];
}

void ManageProvidedVehiclesUI::showVehicles() const {
	const std::vector<IVehicle *> &vehicles = controller.getVehicles();
	char ch = 0;

	if (vehicles.empty()) {
		cout << "You have no vehicles." << endl;
		return;
	}

	do {
		cout << endl << "First vehicle:" << endl;
		cout << **vehicles.begin() << endl;

		stringstream options_stream;

		options_stream << "1 - View all" << endl;
		options_stream << endl;
		options_stream << "0 - Return" << endl;

		cout << options_stream.str();

		string option;
		cout << endl << "Option: ";
		getline(cin, option);

		ch = option[0];

		switch (ch) {
			case '1':
				cout << endl << "=== All Vehicles ===" << endl << endl;
				for (IVehicle *v : vehicles)
					cout << *v << endl;
				break;
			case '0':
				return;
			default:
				cout << endl << "Invalid option, try again..." << endl;
				break;
		}

	} while (ch != '0' && ch != '1');
}