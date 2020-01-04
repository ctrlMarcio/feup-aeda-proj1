#include "ViewInactiveClientsController.h"

ViewInactiveClientsController::ViewInactiveClientsController(ClientManager &clientManager,
															 ContractManager &contractManager)
		: client_manager(clientManager), contract_manager(contractManager) {}

vector<const Client *> ViewInactiveClientsController::getInactiveClients() const {
	return client_manager.getInactiveClients();
}

list<Contract *> ViewInactiveClientsController::getHistoric(const Client &client) const {
	return contract_manager.getContractsOf(client.getIdentificationNumber());
}
