#include "login_page_ui.h"
#include "../../controller/login_page/login_page_controller.h"
#include "../../../exception/invalid_login_exception.h"
#include <sstream>

LoginPageUI::LoginPageUI(UIManager &ui_manager) : ui_manager(ui_manager), controller(ui_manager.getCurrentSession(),
                                                                                     ui_manager.getAuthUserManager(), ui_manager) {}

void LoginPageUI::run() {
    cout << getHeader();

    string identification_number = getIdentificationNumber();

    if (identification_number.empty()) return;

    string password = getPassword();

    if (password.empty()) return;

    try {
        bool login = controller.login(identification_number, password);

        if (login) {
            cout << endl << "Successfully logged in." << endl;
            controller.redirect(identification_number);
        } else {
            cout << endl << "An unexpected error occurred..." << endl;
        }
    } catch (InvalidLoginException &e) {
        cout << endl << e.getMessage() << endl;
    }
}

string LoginPageUI::getHeader() {
    stringstream header_stream;

    header_stream << endl << "Login page" << "                      " << Date().toString() << endl;

    return header_stream.str();
}

string LoginPageUI::getIdentificationNumber() {
    string id;

    bool has_user;

    do {
        cout << endl << "Type your identification number: ";

        getline(cin, id);

        id = trim(id);

        has_user = controller.hasUser(id);

        if (id.empty()) {
            cout << endl << "Your identification number cannot be empty, try again..." << endl;
        } else if (!is_number(id)) {
            cout << endl << "Your identification number can only contain numbers, try again..." << endl;
        } else if (!has_user && id != "0") {
            cout << endl << "There is no user with that identification number, try again..." << endl;
        }
    } while (id.empty() || (!has_user && id != "0") || !is_number(id));

    if (id == "0") return "";
    else return id;
}

string LoginPageUI::getPassword() {
    string password;

    do {
        cout << endl << "Type your password: ";

        getline(cin, password);

        password = trim(password);

        if (password.empty()) {
            cout << endl << "Your password cannot be empty, try again..." << endl;
        }
    } while (password.empty());

    if (password == "0") return "";
    else return password;
}
