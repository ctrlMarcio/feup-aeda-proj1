#include "add_vehicle_ui.h"
#include "../../../util/io_util.h"

AddVehicleUI::AddVehicleUI(UIManager &ui_manager) : controller(ui_manager.getCompany().getUserManager().getProvider(
		ui_manager.getCurrentSession().getUser().getIdentificationNumber())->getVehicleList()) {}

void AddVehicleUI::run() {
	bool valid;
	std::string option;
	do {
		cout << endl;
		cout << R"(What is the type of the vehicle to add? ("passenger" or "commercial"))" << endl;

		getline(cin, option);

		valid = true;

		if (option == "passenger" || option == "p")
			addPassengerVehicle();
		else if (option == "commercial" || option == "c")
			addCommercialVehicle();
		else {
			cout << "The input is invalid." << endl;
			valid = false;
		}
	} while (!valid);

	bool repeated = !controller.isValid();
	if (repeated) {
		cout << "This vehicle already exists!" << endl;
		cout << "Returning ..." << endl;
		return;
	}

	cout << endl << *controller.getVehicle() << endl;

	bool confirmed = io_util::askBool("Do you confirm?");
	if (confirmed) {
		bool valid = controller.confirm();
		if (!valid) {
			cout << "This vehicle already exists!" << endl;
			cout << "Returning ..." << endl;
			return;
		} else {
			cout << "Success!" << endl;
		}
	} else {
		cout << "Returning..." << endl;
	}
}

void AddVehicleUI::addPassengerVehicle() {
	string number_plate = io_util::askString("Number plate:");
	string brand = io_util::askString("Brand:");
	string model = io_util::askString("Model:");
	unsigned year = io_util::askUnsigned("Year:");
	unsigned seat_number = io_util::askUnsigned("Seat number:");

	controller.createVehicle(number_plate, brand, model, year, seat_number);
}

void AddVehicleUI::addCommercialVehicle() {
	string number_plate = io_util::askString("Number plate:");
	string brand = io_util::askString("Brand:");
	string model = io_util::askString("Model:");
	unsigned year = io_util::askUnsigned("Year:");
	double cargo_volume = io_util::askDouble("Cargo volume:");
	double max_weight = io_util::askDouble("Maximum weight:");
	bool refrigerated = io_util::askBool("Refrigerated:");

	controller.createVehicle(number_plate, brand, model, year, cargo_volume, max_weight, refrigerated);
}
