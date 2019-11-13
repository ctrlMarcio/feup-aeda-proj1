#include "client_page_ui.h"
#include <sstream>

ClientPageUI::ClientPageUI(UIManager &ui_manager) : ui_manager(ui_manager), controller(ui_manager.getCurrentSession()) {}

void ClientPageUI::run() {
    char option = 0;

    do {
        option = getOption();
        switch (option) {
            case '1':
                // TODO: View all offers
                break;
            case '2':
                // TODO: View recommended offers
                break;
            case '3':
                // TODO: View rent history
                break;
            case '4':
                // TODO: Manage rented vehicles
                break;
            case '5':
                // TODO: Manage provided vehicles
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

string ClientPageUI::options() {
    stringstream options_stream;

    options_stream << endl << "Client page                     " << Date().toString() << endl;
    options_stream << endl;
    options_stream << "1 - View all offers" << endl;
    options_stream << "2 - View recommended offers" << endl;
    options_stream << "3 - View rent history" << endl;
    options_stream << endl;
    options_stream << "4 - Manage rented vehicles" << endl;
    options_stream << "5 - Manage provided vehicles" << endl;
    options_stream << endl;
    options_stream << "0 - Logout" << endl;

    return options_stream.str();
}

char ClientPageUI::getOption() {
    cout << options();

    string option;

    cout << endl << "Option: ";

    getline(cin, option);

    return option[0];
}