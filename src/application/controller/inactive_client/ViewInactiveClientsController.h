#ifndef FEUP_AEDA_PROJ1_VIEWINACTIVECLIENTSCONTROLLER_H
#define FEUP_AEDA_PROJ1_VIEWINACTIVECLIENTSCONTROLLER_H


#include "../../../model/user/client.h"
#include "../../../model/user/client_manager.h"
#include "../../../model/contract/contract_manager.h"

class ViewInactiveClientsController {
public:
	ViewInactiveClientsController(ClientManager &clientManager, ContractManager &contractManager);

	vector<const Client *> getInactiveClients() const;

	list<Contract> getHistoric(const Client &client);

private:
	ClientManager &client_manager;

	ContractManager &contract_manager;
};


#endif //FEUP_AEDA_PROJ1_VIEWINACTIVECLIENTSCONTROLLER_H
