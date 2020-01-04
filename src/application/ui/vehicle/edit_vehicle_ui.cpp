#include <sstream>
#include "edit_vehicle_ui.h"
#include "../../../util/io_util.h"
#include "../../../exception/invalid_schedule_exception.h"
#include "../../../exception/invalid_date_exception.h"

EditVehicleUI::EditVehicleUI(UIManager &ui_manager) : controller(
		*ui_manager.getCompany().getUserManager().getProvider(
				ui_manager.getCurrentSession().getUser().getIdentificationNumber()),
		ui_manager.getCompany().getOfferManager(), ui_manager.getCompany().getContractManager(),
		ui_manager.getCompany().getUserManager().getClientManager(),
		ui_manager.getCurrentSession()) {}

void EditVehicleUI::run() {
	showAllVehicles();
	int option = chooseVehicle();

	if (!option)
		return;

	if (!controller.isUpToRent()) {
		createOffer();
	} else {
		editOffer();
	}
}

void EditVehicleUI::showAllVehicles() const {
	cout << endl << "=== Vehicles ===" << endl << endl;

	const vector<IVehicle *> &vehicles = controller.getVehicles();
	for (size_t i = 0; i < vehicles.size(); ++i) {
		cout << i + 1 << ")" << endl << *vehicles[i] << endl;
	}
}

int EditVehicleUI::chooseVehicle() {
	int to_edit = io_util::askInt("Choose a vehicle. (0 to return)");

	if (to_edit == 0)
		return to_edit;

	if (to_edit > controller.getVehicles().size() || to_edit < 0) {
		cout << "The vehicle does not exist. Try again..." << endl;
		run();
	}

	controller.setVehicle(controller.getVehicles()[to_edit - 1]);
	return to_edit;
}

void EditVehicleUI::createOffer() {
	char ch = 0;
	do {
		stringstream options_stream;

		options_stream << "1 - Put up to rent" << endl;
		options_stream << endl;
		options_stream << "0 - Return" << endl;

		cout << options_stream.str();

		string option = io_util::askString("Option:");
		ch = option[0];

		switch (ch) {
			case '1':
				addOffer();
				break;
			default:
				cout << endl << "Invalid option, try again..." << endl;
				break;
		}
	} while (ch != '0' && ch != '1' && ch != '2' && ch != '3');
}

void EditVehicleUI::addOffer() {
	list<Schedule> schedules = requestSchedules();
	float price = io_util::askFloat("Price per hour (€):");
	bool valid = controller.createOffer(schedules, price);

	if (!valid) {
		cout << "The offer is invalid, returning ..." << endl;
	} else {
		cout << "Offer created!" << endl;
	}
}

std::list<Schedule> EditVehicleUI::requestSchedules() {
	std::list<Schedule> schedules;
	bool add_more;

	do {
		try {
			Schedule schedule = askSchedule();
			for (auto it = schedules.begin(); it != schedules.end(); ++it)
				if (schedule.interferesWith(*it)) {
					cout << "The schedule conflicts with another one. Merging ..." << endl;

					Schedule to_merge = *it;
					it = schedules.erase(it);

					schedule = schedule.mergeWith(to_merge);
				}

			schedules.push_back(schedule);
			add_more = io_util::askBool("Do you want to add another schedule?");
		} catch (InvalidScheduleException &e) {
			add_more = io_util::askBool("Add another schedule?");
		}
	} while (add_more);

	return schedules;
}

Schedule EditVehicleUI::askSchedule() {
	cout << endl << "Insert a schedule." << endl;
	Date begin = io_util::askDate("Starting when?");
	Date end = io_util::askDate("Finishing when?");

	if (end.isStartingOfDay() && io_util::askBool("Include the last day?")) {
		end = end.addDay();
		end = end.removeSecond();
	}

	if (end.isPast()) {
		cout << "That offer is incorrect. Offers can only be set in the future." << endl;
		throw InvalidScheduleException("The schedule is in the past.");
	}

	if (begin.isPast()) {
		cout << "The beginning of the schedule is in the past. Setting it as this exact moment." << endl;
		begin = Date();
	}

	try {
		Schedule schedule(begin, end);
		return schedule;
	} catch (const InvalidScheduleException &e) {
		cout << "The schedule inserted is invalid. Try again." << endl;
		return askSchedule();
	}
}

Date EditVehicleUI::requestDate() {
	Date date;
	try {
		unsigned day = io_util::askUnsigned("Day:");
		unsigned month = io_util::askUnsigned("Month:");
		unsigned year = io_util::askUnsigned("Year:");
		unsigned hour = io_util::askUnsigned("Hour:");
		unsigned minute = io_util::askUnsigned("Minute:");
		unsigned second = io_util::askUnsigned("Second:");

		date = Date(day, month, year, hour, minute, second);
	} catch (const InvalidDateException &e) {
		cout << "The date is invalid." << " " << e.what() << endl;
		date = requestDate();
	}
	return date;
}

void EditVehicleUI::editOffer() {
	controller.setOffer();
	char ch = 0;
	do {
		stringstream options_stream;

		options_stream << "1 - Remove offer" << endl;
		options_stream << "2 - Add schedule" << endl;
		options_stream << "3 - Edit price" << endl;
		options_stream << endl;
		options_stream << "0 - Return" << endl;

		cout << options_stream.str();

		string option = io_util::askString("Option:");
		ch = option[0];

		switch (ch) {
			case '1':
				if (controller.removeOffer())
					cout << "Offer removed." << endl;
				else
					cout << "Error removing offer." << endl;
				break;
			case '2':
				addSchedule();
				break;
			case '3':
				changePrice();
				break;
			case '0':
				break;
			default:
				cout << endl << "Invalid option, try again..." << endl;
				break;
		}
	} while (ch != '0' && ch != '1' && ch != '2' && ch != '3');
}

void EditVehicleUI::changePrice() {
	float old_price = controller.getOfferPrice();
	if (old_price != -1)
		cout << "The price is of " << old_price << "€/h." << endl;

	float new_price = io_util::askFloat("What's the new price?");
	bool done = controller.changePrice(new_price);

	if (!done)
		cout << "The price is invalid." << endl;
	else
		cout << "Price changed successfully." << endl;
}

void EditVehicleUI::addSchedule() {
	try {
		Schedule schedule = askSchedule();
		controller.addSchedule(schedule);
	} catch (InvalidScheduleException &e) {
		if (io_util::askBool("Add another schedule?"))
			addSchedule();
	}
}

