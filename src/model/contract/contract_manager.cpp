#include "contract_manager.h"

ContractManager::ContractManager(RentalManager &rental_manager, OfferManager &offer_manager) : rental_manager(
        rental_manager), offer_manager(offer_manager) {
}

RentalContract ContractManager::build(IUser *user, Rental &rental) {
    return RentalContract(Date(), user, RENTAL, rental);
}

TransferContract ContractManager::build(IUser *user, Offer &offer) {
    return TransferContract(Date(), user, TRANSFER, offer);
}

bool ContractManager::add(Contract *contract) {
    if (!isValid(contract))
        return false;

    contracts.insert(contract);
    return true;
}

bool ContractManager::isValid(Contract *contract) {
    // TODO
    return true;
}
