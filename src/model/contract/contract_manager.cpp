#include "contract_manager.h"
#include "../rental/rental_manager.h"

ContractManager::ContractManager(RentalManager &rental_manager, OfferManager &offer_manager) : rental_manager(
		rental_manager), offer_manager(offer_manager), contracts(BST<Contract *, contract_less_than>(nullptr)) {
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

unsigned long ContractManager::daysSinceLastContract(const string &id) const {
	Date now;
	unsigned long min_day = -1;

	for (auto it = contracts.begin(); it != contracts.end(); it++) {
		if ((*it)->getUser()->getIdentificationNumber() == id) {
			unsigned long difference = now.dayDifference((*it)->getDate());

			if (difference < min_day || min_day == -1)
				min_day = difference;
		}
	}

	return min_day;
}

std::list<Contract> ContractManager::getContractsOf(const string &id) const {
	std::list<Contract> res;

	for (auto it = contracts.begin(); it != contracts.end(); it++)
		if ((*it)->getUser()->getIdentificationNumber() == id)
			res.push_back(**it);

	return res;
}
