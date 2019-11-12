#include "initial_page_ui.h"

InitialPageUI::InitialPageUI(UIManager &ui_manager) : ui_manager(ui_manager) {}

char getOption(const UIManager &ui_manager);

string options(const UIManager &ui_manager);

string singleOffer(const UIManager &ui_manager, int index);

void InitialPageUI::run() {
    char option = 0;

    do {
        option = getOption(ui_manager);
        switch (option) {
            case '1':
            case '2':
            case '3':
                break;
            case '4':
                // TODO: View more
                break;
            case '8':
                // TODO: Login
                break;
            case '9':
                // TODO: Register
                break;
            case '0':
                break;
            default:
                cout << endl << "Invalid option, try again..." << endl;
                break;
        }
    } while (option != '0');
}

char getOption(const UIManager &ui_manager) {
    cout << options(ui_manager);

    string option;

    cout << endl << "Option: ";

    cin >> option;

    return option[0];
}

string options(const UIManager &ui_manager) {
    stringstream options_stream;

    options_stream << endl << ui_manager.getCompany().getName() << "                    " << Date().toString() << endl;
    options_stream << endl;
    options_stream << "1 - " << singleOffer(ui_manager, 0) << endl;
    options_stream << "2 - " << singleOffer(ui_manager, 1) << endl;
    options_stream << "3 - " << singleOffer(ui_manager, 2) << endl;
    options_stream << "4 - View more..." << endl;
    options_stream << endl;
    options_stream << "8 - Login" << endl;
    options_stream << "9 - Register" << endl;
    options_stream << "0 - Exit" << endl;

    return options_stream.str();
}

string singleOffer(const UIManager &ui_manager, int index) {
    OfferManager offer_manager = ui_manager.getCompany().getOfferManager();

    if (index >= offer_manager.getOffers().size()) return "There are not enough offers to show.";

    Offer &offer = *(offer_manager.getOffers().begin() + index);

    stringstream offer_stream;

    offer_stream << offer.getVehicle().getYear() << " " << offer.getVehicle().getBrand() << " "
                 << offer.getVehicle().getModel() << ", " << fixed << setprecision(2) << offer.getPrice() << " gbp/day";

    return offer_stream.str();
}