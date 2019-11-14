#include "initial_page_ui.h"
#include "../register_page/register_page_ui.h"
#include "../login_page/login_page_ui.h"
#include "../../../exception/invalid_file_exception.h"

InitialPageUI::InitialPageUI(UIManager &ui_manager) : ui_manager(ui_manager),
													  controller(ui_manager.getAuthUserManager(),
																 ui_manager.getCompany(),
																 ui_manager.getDirectory()) {}

void InitialPageUI::run() {
	char option = 0;

	do {
		option = getOption();
		switch (option) {
			case '1':
			case '2':
			case '3':
				break;
			case '4':
				// TODO: View more
				break;
			case '8':
				ui_manager.setCurrent(new LoginPageUI(ui_manager));
				ui_manager.run();
				break;
			case '9':
				ui_manager.setCurrent(new RegisterPageUI(ui_manager));
				ui_manager.run();
				break;
			case '0':
				cout << endl << exitMessage() << endl;
				break;
			default:
				cout << endl << "Invalid option, try again..." << endl;
				break;
		}
	} while (option != '0');
}

string InitialPageUI::options() {
	stringstream options_stream;

	options_stream << endl << ui_manager.getCompany().getName() << "                    " << Date().toString() << endl;
	options_stream << endl;
	options_stream << "1 - " << singleOffer(0) << endl;
	options_stream << "2 - " << singleOffer(1) << endl;
	options_stream << "3 - " << singleOffer(2) << endl;
	options_stream << "4 - View more..." << endl;
	options_stream << endl;
	options_stream << "8 - Login" << endl;
	options_stream << "9 - Register" << endl;
	options_stream << "0 - Exit" << endl;

	return options_stream.str();
}

char InitialPageUI::getOption() {
	cout << options();

	string option;

	cout << endl << "Option: ";

	getline(cin, option);

	return option[0];
}

string InitialPageUI::singleOffer(int index) {
	OfferManager offer_manager = ui_manager.getCompany().getOfferManager();

	if (index >= offer_manager.getOffers().size()) return "There are not enough offers to show.";

	Offer &offer = *(offer_manager.getOffers().begin() + index);

	stringstream offer_stream;

	offer_stream << offer.getVehicle().getYear() << " " << offer.getVehicle().getBrand() << " "
				 << offer.getVehicle().getModel() << ", " << fixed << setprecision(2) << offer.getPrice() << " gbp/day";

	return offer_stream.str();
}

string InitialPageUI::exitMessage() {
	try {
		controller.save();
		return "Data saved successfully.";
	} catch (InvalidFileException &e) {
		return "Could not save the data.";
	}
}
