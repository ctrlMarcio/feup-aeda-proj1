#include <list>
#include "../../../model/rental/rental.h"
#include "view_all_rental_history_ui.h"
#include "../../../util/io_util.h"

ViewAllRentalHistoryUI::ViewAllRentalHistoryUI(UIManager &ui_manager) :
		controller(ui_manager.getCompany().getRentalManager()) {}

void ViewAllRentalHistoryUI::run() {
	const size_t qt_to_show = 5;
	const std::list<Rental> &rentals = controller.getAllRentals();

	showRentals(rentals, 0, qt_to_show);
}

void ViewAllRentalHistoryUI::showRentals(const std::list<Rental> &rentals, const int first, const int qt) const {
	if (rentals.empty()) {
		cout << "There are no rentals yet." << endl;
		return;
	}

	cout << endl;
	cout << "Showing rentals ..." << endl;
	cout << endl;
	auto it = rentals.begin();
	advance(it, first);
	int i = 0;

	for (; it != rentals.end() && i < qt; ++it) {
		cout << (*it).toOneLineDescription() << endl;
		++i;
	}

	cout << endl;
	cout << "Previous (a) / Next (d)" << endl;
	cout << "0 - Main menu" << endl;

	cout << "Option: ";
	string option;
	getline(cin, option);
	option = option[0];

	if (option == "d") {
		int new_first = first + qt;
		if (new_first + qt >= rentals.size())
			new_first = rentals.size() - qt - 1;
		if (new_first < 0)
			new_first = 0;
		showRentals(rentals, new_first, qt);
	} else if (option == "a") {
		int new_first = first - qt;
		if (new_first < 0)
			new_first = 0;
		showRentals(rentals, new_first, qt);
	} else if (option == "0")
		return;
	else {
		cout << "Invalid input." << endl;
		showRentals(rentals, first, qt);
	}
}
