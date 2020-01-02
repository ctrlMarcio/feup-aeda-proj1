#include "view_contracts_page_controller.h"
#include <sstream>
#include <algorithm>

ViewContractsPageController::ViewContractsPageController(ContractManager &contract_manager) : contract_manager(
        contract_manager) {
    for (auto it = contract_manager.getContracts().begin(); it != contract_manager.getContracts().end(); it++)
        contracts.push_back(**it);
}

vector<Contract> ViewContractsPageController::getContracts() const {
    return contracts;
}

void ViewContractsPageController::sortBy(SortField field) {
    switch (field) {
        case DEFAULT:
            break;
        case DATE:
            sort(contracts.begin(), contracts.end(), [](Contract &c1, Contract &c2) {
                return c1.getDate() < c2.getDate();
            });
            break;
        case CLIENT_NAME:
            sort(contracts.begin(), contracts.end(), [](Contract &c1, Contract &c2) {
                return c1.getUser()->getName() < c2.getUser()->getName();
            });
            break;
        case CONTRACT_TYPE:
            sort(contracts.begin(), contracts.end(), [](Contract &c1, Contract &c2) {
                return c1.getContractType() < c2.getContractType();
            });
            break;
    }
}
