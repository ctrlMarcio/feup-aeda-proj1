#include "view_recommended_offers_ui.h"
#include "../../../model/vehicle/commercial_vehicle.h"
#include "../../../model/vehicle/passenger_vehicle.h"
#include "../register_page/register_page_ui.h"
#include "../rental/rent_vehicle_ui.h"
#include <sstream>
#include <iomanip>

using namespace std;

ViewRecommendedOffersUI::ViewRecommendedOffersUI(UIManager &ui_manager) :
		ui_manager(ui_manager),
		controller(ui_manager.getCompany().getUserManager().getRenter(
				ui_manager.getCurrentSession().getUser().getIdentificationNumber())->getPreferenceList(),
				   ui_manager.getCompany().getOfferManager()) {}

void ViewRecommendedOffersUI::run() {
	controller.getRecommendedOffers();
	char option;

	do {
		option = getOffer();

		if (is_number(to_string(option)) && stoi(to_string(option)) - 48 >= 1 &&
			stoi(to_string(option)) - 48 <= controller.getOffers(current_page, MAX_PER_PAGE).size()) {
			Offer offer = controller.getOffer(current_page, MAX_PER_PAGE, stoi(to_string(option)) - 48 - 1);

			selectOffer(offer);
		} else {
			switch (option) {
				case 'A':
					increasePage();
					break;
				case 'D':
					decreasePage();
					break;
				case '0':
					break;
				default:
					cout << endl << "Invalid option, try again..." << endl;
					break;
			}
		}
	} while (option != '0');
}

char ViewRecommendedOffersUI::getOffer() {
	cout << offers();

	string option;

	cout << endl << "Option: ";

	getline(cin, option);

	return option[0];
}

string ViewRecommendedOffersUI::offers() {
	stringstream options_stream;

	options_stream << endl << "Recommended offers page" << "        " << Date().toString() << endl;
	options_stream << endl;
	options_stream << "A/D - Previous/next page" << endl;
	options_stream << endl;

	vector<Offer> page_offers = controller.getOffers(current_page, MAX_PER_PAGE);

	int number = 1;

	for (Offer &offer : page_offers) {
		options_stream << number++ << " - " << singleOffer(offer) << endl;
	}

	if (page_offers.empty()) {
		options_stream << endl << "There is nothing to show in the page." << endl;
	} else {
		int page_count = controller.getPageCount(MAX_PER_PAGE);

		options_stream << endl << "Page " << current_page << "/" << page_count << endl;
	}

	options_stream << endl;
	options_stream << "0 - Exit" << endl;

	return options_stream.str();
}

string ViewRecommendedOffersUI::singleOffer(Offer &offer) {
	stringstream offer_stream;

	offer_stream << offer.getVehicle().getYear() << " " << offer.getVehicle().getBrand() << " "
				 << offer.getVehicle().getModel() << ", " << fixed << setprecision(2) << offer.getPrice() << " €/h";

	return offer_stream.str();
}

void ViewRecommendedOffersUI::selectOffer(Offer &offer) {
	stringstream complete_offer_stream;

	complete_offer_stream << endl << offer.getVehicle().getYear() << " " << offer.getVehicle().getBrand()
						  << " " << offer.getVehicle().getModel() << " [" << offer.getVehicle().getNumberPlate() << "]"
						  << endl;
	complete_offer_stream << endl;
	complete_offer_stream << "Price: " << fixed << setprecision(2) << offer.getPrice() << " €/h" << endl;
	complete_offer_stream << endl;
	complete_offer_stream << "Type: " << offer.getVehicle().getType() << endl;

	if (offer.getVehicle().getType() == CommercialVehicle::TYPE) {
		auto &vehicle = dynamic_cast<CommercialVehicle &>(offer.getVehicle());
		complete_offer_stream << "Max volume: " << fixed << setprecision(2) << vehicle.getCargoVolume()
							  << " cubic meters" << endl;
		complete_offer_stream << "Max weight: " << fixed << setprecision(2) << vehicle.getMaxWeight() << " kg" << endl;
		complete_offer_stream << "Refrigerated: " << (vehicle.isRefrigerated() ? "yes" : "no") << endl;
	} else if (offer.getVehicle().getType() == PassengerVehicle::TYPE) {
		auto &vehicle = dynamic_cast<PassengerVehicle &>(offer.getVehicle());
		complete_offer_stream << "Seats: " << vehicle.getSeatNumber() << endl;
	}

	complete_offer_stream << endl;
	complete_offer_stream << "Available on..." << endl;

	for (const Schedule &schedule : offer.getAvailableSchedules()) {
		complete_offer_stream << " - " << schedule << endl;
	}

	complete_offer_stream << endl;
	complete_offer_stream << "Do you wish to rent this vehicle? (Y/N) ";

	cout << complete_offer_stream.str();

	string input;

	getline(cin, input);

	if (input == "Y" || input == "y") {
		if (ui_manager.getCurrentSession().getUser() == AuthUser("", "", "")) {
			cout << endl << "You dont have an account, do you wish to create an account? (Y/N) ";
			string create_account;

			getline(cin, create_account);

			if (create_account == "Y") {
				ui_manager.setCurrent(new RegisterPageUI(ui_manager));
				ui_manager.run();
			}
		} else {
			ui_manager.setCurrent(new RentVehicleUI(ui_manager, offer));
			RentVehicleUI(ui_manager, offer).run();
		}
	}
}

void ViewRecommendedOffersUI::increasePage() {
	if (current_page - 1 < 1) {
		cout << endl << "That page is invalid, try another..." << endl;
		return;
	}

	current_page--;
}

void ViewRecommendedOffersUI::decreasePage() {
	int page_count = controller.getPageCount(MAX_PER_PAGE);

	if (current_page + 1 > page_count) {
		cout << endl << "That page is invalid, try another..." << endl;
		return;
	}

	current_page++;
}