#include "rent_vehicle_ui.h"
#include "../../../util/io_util.h"
#include "../../../exception/invalid_date_exception.h"
#include "../../../exception/invalid_schedule_exception.h"

RentVehicleUI::RentVehicleUI(UIManager &ui_manager, Offer &offer) :
		controller(ui_manager.getCompany().getRentalManager(),
				   offer,
				   *ui_manager.getCompany().getUserManager().getRenter(
						   ui_manager.getCurrentSession().getUser().getIdentificationNumber()),
				   ui_manager.getCompany().getContractManager(),
				   ui_manager.getCompany().getUserManager().getClientManager()) {}

void RentVehicleUI::run() {
	showVehicle();

	showAvailableSchedules();
	Rental rental = requestRental();

	bool confirmed = confirms(rental);

	if (confirmed) {
		bool valid = controller.confirm(rental);

		if (!valid)
			cout << "The rental is invalid, returning ..." << endl;
		else
			cout << endl << "Rented!" << endl;
	}
}

void RentVehicleUI::showVehicle() {
	cout << endl;
	cout << controller.getOffer().getVehicle();
	cout << endl;
}

void RentVehicleUI::showAvailableSchedules() {
	cout << "Available schedules: " << endl;
	for (Schedule s : controller.getOffer().getAvailableSchedules())
		cout << s << endl;
	cout << endl;
}

Rental RentVehicleUI::requestRental() {
	Date begin = io_util::askDate("Starting when?");
	Date end = io_util::askDate("Ending when?");

	try {
		Schedule(begin, end);
	} catch (const InvalidScheduleException &e) {
		cout << "The schedule inserted is invalid. Try again." << endl;
		return requestRental();
	}
	Rental rental = controller.createRental(begin, end);
	if (!controller.isValid(rental)) {
		cout << "The rental is invalid. Try again." << endl;
		return requestRental();
	}

	return rental;
}

Date RentVehicleUI::requestDate() {
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

bool RentVehicleUI::confirms(Rental &rental) {
	cout << endl << rental.toOneLineDescription() << endl;
	cout << endl;
	return io_util::askBool("Do you confirm? (Y/N)");
}
