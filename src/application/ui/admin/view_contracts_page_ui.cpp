#include "view_contracts_page_ui.h"
#include <sstream>

ViewContractsPageUI::ViewContractsPageUI(UIManager &ui_manager) : ui_manager(ui_manager), controller(
        ui_manager.getCompany().getContractManager()) {}

void ViewContractsPageUI::run() {
    cout << getHeader();
    cout << getContracts();

    string option;

    do {
        option = getSortOption();

        if (option != "0"){
            SortField field = getSortField();

            if (field != DEFAULT) {
                controller.sortBy(field);

                cout << getContracts();
            }
        }
    } while (option != "0");
}

string ViewContractsPageUI::getHeader() {
    stringstream header_stream;

    header_stream << endl << "View contracts" << "                  " << Date().toString() << endl;

    return header_stream.str();
}

string ViewContractsPageUI::getContracts() {
    stringstream contracts_stream;

    contracts_stream << endl;

    for (const Contract &contract : controller.getContracts())
        contracts_stream << contract.toString() << endl;

    return contracts_stream.str();
}

string ViewContractsPageUI::getSortOption() {
    stringstream options_stream;

    options_stream << "1 - Sort contracts" << endl << endl;
    options_stream << "0 - Exit" << endl;
    options_stream << endl << "Option: ";

    cout << options_stream.str();

    string option;

    getline(cin, option);

    while (option != "0" && option != "1") {
        cout << endl << "Invalid option, try again..." << endl;

        cout << endl << "Option: ";

        getline(cin, option);
    }

    return option;
}

SortField ViewContractsPageUI::getSortField() {
    stringstream fields_stream;

    fields_stream << "Select the field to sort the contracts..." << endl << endl;
    fields_stream << "1 - Concluded date" << endl;
    fields_stream << "2 - Renter/provider name" << endl;
    fields_stream << "3 - Contract type" << endl;
    fields_stream << endl << "Field: ";

    cout << fields_stream.str();

    string field;

    getline(cin, field);

    while (field != "0" && field != "1" && field != "2" && field != "3") {
        cout << endl << "Invalid field, try again... " << endl;

        cout << endl << "Field: ";

        getline(cin, field);
    }

    switch (field[0]) {
        case '1':
            return DATE;
        case '2':
            return CLIENT_NAME;
        case '3':
            return CONTRACT_TYPE;
        default:
            return DEFAULT;
    }
}
