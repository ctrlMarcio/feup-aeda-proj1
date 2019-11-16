#include "rent_vehicle_ui.h"
#include "../../../util/io_util.h"
#include "../../../exception/invalid_date_exception.h"
#include "../../../exception/invalid_schedule_exception.h"

RentVehicleUI::RentVehicleUI(UIManager &ui_manager, Offer &offer) :
		controller(ui_manager.getCompany().getRentalManager(),
				   offer,
				   *ui_manager.getCompany().getUserManager().getRenter(ui_manager.getCurrentSession().getUser().getIdentificationNumber())) {}

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
			cout << "Rented!" << endl;
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
	cout << "Let's insert the start date and time." << endl;
	cout << "Starting when?" << endl;
	Date begin = requestDate();
	cout << endl << "Finishing when?";
	Date end = requestDate();

	try {
		Schedule(begin, end);
	} catch (const InvalidScheduleException &e) {
		cout << "The schedule inserted is invalid. Try again." << endl;
		return requestRental();
	}
	return controller.createRental(begin, end);
}

Date RentVehicleUI::requestDate() {
	Date date;
	try {
		unsigned day = io_util::askUnsigned("Day: ");
		unsigned month = io_util::askUnsigned("Month: ");
		unsigned year = io_util::askUnsigned("Year: ");
		unsigned hour = io_util::askUnsigned("Hour: ");
		unsigned minute = io_util::askUnsigned("Minute: ");
		unsigned second = io_util::askUnsigned("Second: ");

		date = Date(day, month, year, hour, minute, second);
	} catch (const InvalidDateException &e) {
		cout << "The date is invalid." << " " << e.what() << endl;
		date = requestDate();
	}
	return date;
}

bool RentVehicleUI::confirms(Rental &rental) {
	cout << endl << rental.toOneLineDescription() << endl;
	return io_util::askBool("Do you confirm?");
}
