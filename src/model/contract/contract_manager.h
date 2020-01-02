#ifndef FEUP_AEDA_PROJ1_CONTRACT_MANAGER_H
#define FEUP_AEDA_PROJ1_CONTRACT_MANAGER_H


#include "rental_contract.h"
#include "transfer_contract.h"
#include "../../util/bst.h"
#include "../rental/rental_manager.h"

struct contract_less_than {
	bool operator()(const Contract *contract1, const Contract *contract2) const {
		return *contract1 < *contract2;
	}
};

class ContractManager {
public:
    ContractManager(RentalManager &rental_manager, OfferManager &offer_manager);

    static RentalContract build(IUser *user, Rental &rental);

    static TransferContract build(IUser *user, Offer &offer);

    bool add(Contract *contract);

    bool isValid(Contract *contract);

	/*!
	 * Gets the number of days since the last contract made by a user.
	 * If the user has no contracts, returns -1.
	 *
	 * @param id the id of the user
	 * @return the number of days passed, or -1
	 */
	long daysSinceLastContract(const string &id) const;

	/*!
	 * Gets all the past contracts of a given user ordered by date of realization.
	 *
	 * @param id the id of the user
	 * @return the list of contracts
	 */
	std::list<Contract> getContractsOf(const string &id) const;

private:
    RentalManager &rental_manager;

    OfferManager &offer_manager;

	BST<Contract *, contract_less_than> contracts;
};


#endif //FEUP_AEDA_PROJ1_CONTRACT_MANAGER_H
