#include "view_contracts_page_ui.h"
#include <sstream>

ViewContractsPageUI::ViewContractsPageUI(UIManager &ui_manager) : ui_manager(ui_manager), controller(
        ui_manager.getCompany().getContractManager()) {}

void ViewContractsPageUI::run() {

}

string ViewContractsPageUI::getHeader() {
    stringstream header_stream;

    header_stream << endl << "View contracts" << "                  " << Date().toString() << endl;

    return header_stream.str();
}

string ViewContractsPageUI::getContracts() {
    return controller.getContracts();
}
