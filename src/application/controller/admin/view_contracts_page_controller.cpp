#include "view_contracts_page_controller.h"
#include <sstream>

ViewContractsPageController::ViewContractsPageController(ContractManager &contract_manager) : contract_manager(
        contract_manager) {}

string ViewContractsPageController::getContracts() {
    stringstream contracts_stream;



    return contracts_stream.str();
}

void ViewContractsPageController::sortBy(SortField field) {
    contract_manager.
}
