#include "admin_page_ui.h"
#include <sstream>
#include "../rental/view_all_rental_history_ui.h"
#include "../vehicle/manage_provided_vehicles_ui.h"
#include "../vehicle/maintenance/manage_maintenance_services_ui.h"

AdminPageUI::AdminPageUI(UIManager &ui_manager) : ui_manager(ui_manager), controller(ui_manager.getCurrentSession()) {}

void AdminPageUI::run() {
    char option = 0;

    do {
        option = getOption();
        switch (option) {
            case '1':
				ui_manager.setCurrent(new ViewAllRentalHistoryUI(ui_manager));
				ui_manager.run();
                break;
            case '2':
				ui_manager.setCurrent(new ManageProvidedVehiclesUI(ui_manager));
				ui_manager.run();
                break;
			case '3':
				ui_manager.setCurrent(new ManageMaintenanceServicesUI(ui_manager));
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

string AdminPageUI::options() {
    stringstream options_stream;

    options_stream << endl << "Admin page                      " << Date().toString() << endl;
    options_stream << endl;
    options_stream << "1 - View rental history" << endl;
    options_stream << endl;
    options_stream << "2 - Manage provided vehicles" << endl;
    options_stream << endl;
	options_stream << "3 - Manage maintenance services" << endl;
	options_stream << endl;
    options_stream << "0 - Logout" << endl;

    return options_stream.str();
}

char AdminPageUI::getOption() {
    cout << options();

    string option;

    cout << endl << "Option: ";

    getline(cin, option);

    return option[0];
}