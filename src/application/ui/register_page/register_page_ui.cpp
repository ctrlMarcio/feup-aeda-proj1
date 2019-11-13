#include "register_page_ui.h"

#include "../../../util/string_util.h"

using namespace string_util;

RegisterPageUI::RegisterPageUI(UIManager &ui_manager) : ui_manager(ui_manager), controller(
        RegisterPageController(ui_manager.getAuthUserManager(), ui_manager.getCompany())) {
}

void RegisterPageUI::run() {
    cout << getHeader();

    string user_type = getUserType();

    if (user_type.empty()) return;

    string name = getName();

    if (name.empty()) return;

    string identification_number = getIdentificationNumber();

    if (identification_number.empty()) return;

    string address = getAddress();

    if (address.empty()) return;

    if (controller.createUser(user_type, name, identification_number, address)) {
        string password = controller.getPassword(identification_number);
        cout << endl << "User successfully created. Your password is " << password << endl;
    } else {
        cout << endl << "An unexpected error occurred!" << endl;
    }
}

string RegisterPageUI::getHeader() {
    stringstream header_stream;

    header_stream << endl << "Register page" << "                   " << Date().toString() << endl;

    return header_stream.str();
}

string RegisterPageUI::getUserType() {
    stringstream user_types;

    user_types << endl << "Which user do you wish to become? [0 to exit]" << endl;
    user_types << "1 - Client" << endl;
    user_types << "2 - Company Client" << endl;

    cout << user_types.str();

    string user_type;

    char option;

    do {
        cout << endl << "Option: ";

        string input;
        getline(cin, input);
        input = trim(input);
        option = input[0];

        switch (option) {
            case '0':
                user_type = "";
                break;
            case '1':
                user_type = "client";
                break;
            case '2':
                user_type = "company_client";
                break;
            default:
                cout << endl << "Invalid option, try again..." << endl;
                break;
        }
    } while (option != '0' && option != '1' && option != '2');

    return user_type;
}

string RegisterPageUI::getName() {
    string name;

    do {
        cout << endl << "Type your name: ";

        getline(cin, name);

        name = trim(name);

        if (name.empty()) {
            cout << endl << "Your name cannot be empty, try again..." << endl;
        }
    } while (name.empty());

    if (name == "0") return "";
    else return name;
}

string RegisterPageUI::getIdentificationNumber() {
    string id;

    bool has_user;

    do {
        cout << endl << "Type your identification number: ";

        getline(cin, id);

        id = trim(id);

        if (id.empty()) {
            cout << endl << "Your identification number cannot be empty, try again..." << endl;
        } else if (!is_number(id)) {
            cout << endl << "Your identification number can only contain numbers, try again..." << endl;
        }

        has_user = controller.hasUser(id);

        if (has_user) {
            cout << endl << "There is already a user with that identification number, try another..." << endl;
        }
    } while (id.empty() || has_user || !is_number(id));

    if (id == "0") return "";
    else return id;
}

string RegisterPageUI::getAddress() {
    string address;

    do {
        cout << endl << "Type your address: ";

        getline(cin, address);

        address = trim(address);

        if (address.empty()) {
            cout << endl << "Your address cannot be empty, try again..." << endl;
        }
    } while (address.empty());

    if (address == "0") return "";
    else return address;
}
