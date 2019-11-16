#include "view_rental_history_page_ui.h"
#include <sstream>

ViewRentalHistoryPageUI::ViewRentalHistoryPageUI(UIManager &ui_manager) : ui_manager(ui_manager), controller(
        ui_manager.getCompany().getRentalManager()) {}

void ViewRentalHistoryPageUI::run() {
    string option;

    do {
        option = getOption();
        switch (toupper(option[0])) {
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
    } while (option[0] != '0');
}

string ViewRentalHistoryPageUI::rentals() {
    stringstream options_stream;

    options_stream << endl << "Rental history page" << "                     " << Date().toString() << endl;
    options_stream << endl;
    options_stream << "A/D - Previous/next page" << endl;
    options_stream << endl;

    vector<Rental *> page_rentals = controller.getRentals(
            ui_manager.getCurrentSession().getUser().getIdentificationNumber(), current_page, MAX_PER_PAGE);

    int number = 1;

    for (Rental *rental : page_rentals) {
        options_stream << number++ << " - " << rental->toOneLineDescription() << endl;
    }

    if (page_rentals.empty()) {
        options_stream << "There is nothing to show in the page." << endl;
    } else {
        int page_count = controller.getPageCount(ui_manager.getCurrentSession().getUser().getIdentificationNumber(),
                                                 MAX_PER_PAGE);

        options_stream << endl << "Page " << current_page << "/" << page_count << endl;
    }

    options_stream << endl;
    options_stream << "0 - Exit" << endl;

    return options_stream.str();
}

string ViewRentalHistoryPageUI::getOption() {
    cout << rentals();

    string option;

    cout << endl << "Option: ";

    getline(cin, option);

    return option;
}

void ViewRentalHistoryPageUI::increasePage() {
    if (current_page - 1 < 1) {
        cout << endl << "That page is invalid, try another..." << endl;
        return;
    }

    current_page--;
}

void ViewRentalHistoryPageUI::decreasePage() {
    int page_count = controller.getPageCount(ui_manager.getCurrentSession().getUser().getIdentificationNumber(),
                                             MAX_PER_PAGE);

    if (current_page + 1 > page_count) {
        cout << endl << "That page is invalid, try another..." << endl;
        return;
    }

    current_page++;
}
