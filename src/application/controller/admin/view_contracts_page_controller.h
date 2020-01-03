#ifndef FEUP_AEDA_PROJ1_VIEW_CONTRACTS_PAGE_CONTROLLER_H
#define FEUP_AEDA_PROJ1_VIEW_CONTRACTS_PAGE_CONTROLLER_H

#include <string>
#include "../../../model/contract/contract_manager.h"
#include <vector>

using namespace std;

enum SortField {
    DEFAULT, DATE, CLIENT_NAME, CONTRACT_TYPE, VEHICLE_YEAR
};

class ViewContractsPageController {
public:
    explicit ViewContractsPageController(ContractManager &contract_manager);

    vector<Contract *> getContracts() const;

    void sortBy(SortField field);

private:
    ContractManager &contract_manager;

    vector<Contract *> contracts;
};


#endif //FEUP_AEDA_PROJ1_VIEW_CONTRACTS_PAGE_CONTROLLER_H
