#include "login_page_ui.h"
#include "../../controller/login_page/login_page_controller.h"
#include <sstream>

LoginPageUI::LoginPageUI(UIManager &ui_manager) : ui_manager(ui_manager), controller(ui_manager.getCurrentSession(),
                                                                                     ui_manager.getAuthUserManager()) {}

void LoginPageUI::run() {
    cout << getHeader();

    string identification_number = getIdentificationNumber();

    if (identification_number.empty()) return;

    string password = getPassword();

    if (password.empty()) return;
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

        if (id.empty()) {
            cout << endl << "Your identification number cannot be empty, try again..." << endl;
        } else if (!is_number(id)) {
            cout << endl << "Your identification number can only contain numbers, try again..." << endl;
        }

        has_user = controller.hasUser(id);

        if (!has_user) {
            cout << endl << "There is no user with that identification number, try again..." << endl;
        }
    } while (id.empty() || !has_user || !is_number(id));

    if (id == "0") return "";
    else return id;
}

string LoginPageUI::getPassword() {

}
