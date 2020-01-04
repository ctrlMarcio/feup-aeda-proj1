#include "view_contracts_page_controller.h"
#include "../../../util/string_util.h"
#include <sstream>
#include <algorithm>

ViewContractsPageController::ViewContractsPageController(ContractManager &contract_manager) : contract_manager(
        contract_manager) {
    for (auto it = contract_manager.getContracts().begin(); it != contract_manager.getContracts().end(); it++)
        contracts.push_back(*it);
}

vector<Contract *> ViewContractsPageController::getContracts() const {
    return contracts;
}

void ViewContractsPageController::sortBy(SortField field) {
    switch (field) {
        case DEFAULT:
            break;
        case DATE:
            sort(contracts.begin(), contracts.end(), [](const Contract *c1, const Contract *c2) {
                return c1->getDate() < c2->getDate();
            });
            break;
        case CLIENT_NAME:
            sort(contracts.begin(), contracts.end(), [](const Contract *c1, const Contract *c2) {
				return string_util::capitalize(c1->getUser()->getName()) <
					   string_util::capitalize(c2->getUser()->getName());
            });
            break;
        case CONTRACT_TYPE:
            sort(contracts.begin(), contracts.end(), [](const Contract *c1, const Contract *c2) {
                return c1->getContractType() < c2->getContractType();
            });
            break;
        case VEHICLE_YEAR:
            sort(contracts.begin(), contracts.end(), [](Contract *c1, Contract *c2) {
                return c1->getOffer().getVehicle().getYear() < c2->getOffer().getVehicle().getYear();
            });
            break;
    }
}

void ViewContractsPageController::invert() {
	std::reverse(contracts.begin(), contracts.end());
}
