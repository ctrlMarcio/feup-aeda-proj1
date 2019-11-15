#include <iostream>
#include "manage_preferences_ui.h"
#include "../../../util/io_util.h"

ManagePreferencesUI::ManagePreferencesUI(const UIManager &ui_manager) :
		controller(ManagePreferencesController(ui_manager.getCompany().
				getUserManager().getRenter(ui_manager.getCurrentSession().getUser().
				getIdentificationNumber()).getPreferenceList())) {}

void ManagePreferencesUI::run() {
	std::string option;

	option = addOrRemovePreference();

	if (option == "a")
		addPreference();
	if (option == "r")
		removePreference();
	if (option == "s")
		showPreferences();

	cout << "Success!" << endl;
}

void ManagePreferencesUI::showPreferences() {
	cout << endl;
	PassengerPreference *pp = controller.getPassengerPreference();
	CommercialPreference *cp = controller.getCommercialPreference();

	if (pp == nullptr)
		cout << "Passenger preference is nonexistent.";
	else
		cout << *pp;

	cout << endl << endl;

	if (cp == nullptr)
		cout << "Commercial preference is nonexistent.";
	else
		cout << *cp;

	cout << endl;
}

void ManagePreferencesUI::addPreference() {
	std::string option;
	cout << endl;
	cout << R"(What is the type of the vehicle preference? ("passenger" or "commercial"))" << endl;

	getline(cin, option);

	if (option == "passenger")
		addPassengerPreference();
	else if (option == "commercial")
		addCommercialPreference();
	else {
		cout << "The inserted value is invalid" << endl;
		addPreference();
	}
}

void ManagePreferencesUI::addCommercialPreference() {
	unsigned min_year = io_util::askUnsigned("What is the minimum manufactoring year desired?");
	float min_cargo_volume = io_util::askFloat("What is the minimum cargo volume desired?");
	float min_max_weight = io_util::askFloat("What is the minimum desired weight capacity?");
	bool refrigerated = io_util::askBool("Should the vehicle be refrigerated?");

	bool valid = controller.addPreference(min_year, min_cargo_volume, min_max_weight, refrigerated);
	if (!valid)
		addCommercialPreference();
}

void ManagePreferencesUI::addPassengerPreference() {
	unsigned min_year = io_util::askUnsigned("What is the minimum manufactoring year desired?");
	unsigned seat_number = io_util::askUnsigned("What is the desired number of seats?");

	bool valid = controller.addPreference(min_year, seat_number);
	if (!valid)
		addPassengerPreference();
}

string ManagePreferencesUI::addOrRemovePreference() const {
	std::string option;
	bool invalid;
	cout << endl;
	cout << "Do you want to (s)ee the preferences, (a)dd or (r)emove one?" << endl;
	do {
		getline(cin, option);

		invalid = option != "a" && option != "add" && option != "r" && option != "remove"
				  && option != "s" && option != "see";

		if (invalid)
			cout << "Please choose a correct option... (s)ee all, (a)dd or (r)emove a preference?" << endl;

	} while (invalid);

	option = option[0];
	return option;
}

void ManagePreferencesUI::removePreference() {
	string option = whatPreferenceRemove();
	option = option[0];

	if (option == "p")
		controller.removePassengerPreference();
	else if (option == "c")
		controller.removeCommercialPreference();
	else {
		cout << "The inserted value is invalid" << endl;
		removePreference(); //invalid value
	}
}

string ManagePreferencesUI::whatPreferenceRemove() {
	string option;

	cout << endl;
	cout << "Do you want to remove the (c)ommercial or the (p)assenger preference?" << endl;

	getline(cin, option);

	if (option != "c" && option != "p" && option != "commercial" && option != "passenger") {
		cout << "The input is invalid." << endl;
		removePreference();
	}
	return option;
}
