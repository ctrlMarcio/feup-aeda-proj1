#ifndef FEUP_AEDA_PROJ1_VIEW_CONTRACTS_PAGE_CONTROLLER_H
#define FEUP_AEDA_PROJ1_VIEW_CONTRACTS_PAGE_CONTROLLER_H

#include <string>
#include "../../../model/contract/contract_manager.h"

using namespace std;

enum SortField {
    DEFAULT, CLIENT_NAME, CONTRACT_TYPE, VEHICLE_YEAR;
};

class ViewContractsPageController {
public:
    explicit ViewContractsPageController(ContractManager &contract_manager);

    string getContracts();

    void sortBy(SortField field);

private:
    ContractManager &contract_manager;

    BST<>
};


#endif //FEUP_AEDA_PROJ1_VIEW_CONTRACTS_PAGE_CONTROLLER_H
