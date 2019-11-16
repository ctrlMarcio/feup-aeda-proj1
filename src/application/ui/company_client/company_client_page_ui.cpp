#include "company_client_page_ui.h"
#include "../preference/manage_preferences_ui.h"
#include "../offer/view_offers_page_ui.h"
#include "../offer/view_recommended_offers_ui.h"
#include "../renter/view_rental_history_page_ui.h"
#include "../renter/manage_rented_vehicles_page_ui.h"
#include <sstream>

CompanyClientPageUI::CompanyClientPageUI(UIManager &ui_manager) : ui_manager(ui_manager), controller(ui_manager.getCurrentSession()) {}

void CompanyClientPageUI::run() {
    char option = 0;

    do {
        option = getOption();
        switch (option) {
            case '1':
				ui_manager.setCurrent(new ViewOffersPageUI(ui_manager));
				ui_manager.run();
                break;
            case '2':
				ui_manager.setCurrent(new ViewRecommendedOffersUI(ui_manager));
				ui_manager.run();
                break;
            case '3':
                ui_manager.setCurrent(new ViewRentalHistoryPageUI(ui_manager));
                ui_manager.run();
                break;
            case '4':
                ui_manager.setCurrent(new ManageRentedVehiclesPageUI(ui_manager));
                ui_manager.run();
                break;
			case '5':
				ui_manager.setCurrent(new ManagePreferencesUI(ui_manager));
				ui_manager.run();
				break;
            case '0':
                controller.logout();
                break;
            default:
                cout << endl << "Invalid option, try again..." << endl;
                break;
        }
    } while (option != '0');
}

string CompanyClientPageUI::options() {
    stringstream options_stream;

    options_stream << endl << "Company Client page             " << Date().toString() << endl;
    options_stream << endl;
    options_stream << "1 - View all offers" << endl;
    options_stream << "2 - View recommended offers" << endl;
    options_stream << "3 - View rental history" << endl;
    options_stream << endl;
    options_stream << "4 - Manage rented vehicles" << endl;
	options_stream << "5 - Manage preferences" << endl;
    options_stream << endl;
    options_stream << "0 - Logout" << endl;

    return options_stream.str();
}

char CompanyClientPageUI::getOption() {
    cout << options();

    string option;

    cout << endl << "Option: ";

    getline(cin, option);

    return option[0];
}