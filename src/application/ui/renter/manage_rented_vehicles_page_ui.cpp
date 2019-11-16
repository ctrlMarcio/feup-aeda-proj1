#include "manage_rented_vehicles_page_ui.h"
#include "../../../exception/invalid_date_exception.h"
#include <sstream>

using namespace string_util;

ManageRentedVehiclesPageUI::ManageRentedVehiclesPageUI(UIManager &ui_manager) : ui_manager(ui_manager),
                                                                                controller(
                                                                                        ui_manager.getCurrentSession(),
                                                                                        ui_manager.getCompany().getRentalManager()) {}

void ManageRentedVehiclesPageUI::run() {
    string option;

    do {
        option = getRental();

        if (option[0] != '0' && is_number(option) && stoi(option) >= 1 &&
            stoi(option) <= controller.getActiveRentals().size()) {
            Rental *rental = controller.getActiveRentals()[stoi(option) - 1];

            Date date;

            string string_date = getDate(date);

            if (string_date.empty()) return;

            controller.setDeliveryDate(rental, date);
        } else {
            switch (toupper(option[0])) {
                case '0':
                    break;
                default:
                    cout << endl << "Invalid option, try again..." << endl;
                    break;
            }
        }
    } while (option[0] != '0');
}

string ManageRentedVehiclesPageUI::rentals() {
    stringstream options_stream;

    options_stream << endl << "Rental manage page" << "                     " << Date().toString() << endl;
    options_stream << endl;

    vector<Rental *> page_rentals = controller.getActiveRentals();

    int number = 1;

    for (Rental *rental : page_rentals) {
        options_stream << number++ << " - " << rental->toOneLineDescription() << endl;
    }

    options_stream << endl;
    options_stream << "0 - Exit" << endl;

    return options_stream.str();
}

string ManageRentedVehiclesPageUI::getRental() {
    cout << rentals();

    string option;

    cout << endl << "Option: ";

    getline(cin, option);

    return option;
}

string ManageRentedVehiclesPageUI::getDate(Date &date) {
    string date_string;

    bool isDate;

    do {
        cout << endl << "Type the date [DD/MM/YYYY HH:MM]: ";

        getline(cin, date_string);

        date_string = trim(date_string);

        isDate = verifyFormat(date, date_string);

        if (date_string.empty()) {
            cout << endl << "The date, try again..." << endl;
        } else if (!isDate) {
            cout << endl << "The date format is not valid, try again..." << endl;
        }
    } while (date_string.empty() || !isDate);

    if (date_string == "0") return "";
    else return date_string;
}

bool ManageRentedVehiclesPageUI::verifyFormat(Date &date, const string &date_string) {
    vector<string> main_fields = split(date_string, " ");
    if (main_fields.size() != 2) return false;
    string left_field = main_fields[0];
    string right_field = main_fields[1];
    vector<string> left_fields = split(left_field, "/");
    vector<string> right_fields = split(right_field, ":");
    if (left_fields.size() != 3 || right_fields.size() != 2) return false;
    string dd = left_fields[0];
    string mm = left_fields[1];
    string yyyy = left_fields[2];
    string hh = right_fields[0];
    string minmin = right_fields[1];
    if (!(is_number(dd) && is_number(mm) && is_number(yyyy) && is_number(hh) && is_number(minmin))) return false;
    try {
        date = Date(stoi(dd), stoi(mm), stoi(yyyy), stoi(hh), stoi(minmin));
        return true;
    } catch (InvalidDateException e){
        return false;
    }
}
