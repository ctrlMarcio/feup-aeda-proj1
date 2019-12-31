#ifndef FEUP_AEDA_PROJ1_CONTRACT_MANAGER_H
#define FEUP_AEDA_PROJ1_CONTRACT_MANAGER_H


#include "../rental/rental_manager.h"
#include "rental_contract.h"
#include "transfer_contract.h"
#include "../../util/bst.h"

class ContractManager {
public:
    ContractManager(RentalManager &rental_manager, OfferManager &offer_manager);

    static RentalContract build(IUser *user, Rental &rental);

    static TransferContract build(IUser *user, Offer &offer);

    bool add(Contract *contract);

    bool isValid(Contract *contract);

private:
    RentalManager &rental_manager;

    OfferManager &offer_manager;

    BST<Contract *> contracts = BST<Contract *>(nullptr);
};


#endif //FEUP_AEDA_PROJ1_CONTRACT_MANAGER_H
