#include "ViewInactiveClientsUI.h"
#include "../../../util/io_util.h"

ViewInactiveClientsUI::ViewInactiveClientsUI(UIManager &ui_manager) :
		controller(ui_manager.getCompany().getUserManager().getClientManager(),
				   ui_manager.getCompany().getContractManager()) {}

void ViewInactiveClientsUI::run() {
	vector<const Client *> inactive_clients = controller.getInactiveClients();

	if (inactive_clients.empty()) {
		cout << endl << "There are no inactive clients." << endl << "Returning ..." << endl;
		return;
	}

	printClients(inactive_clients);

	bool valid;
	Client client("", "", "");
	do {
		valid = true;

		int choice = io_util::askInt("Client (-1 to return):");
		if (choice == -1)
			return;

		try {
			client = *inactive_clients.at(choice - 1);
		} catch (out_of_range &e) {
			cout << "The client does not exist." << endl;
			valid = false;
		}
	} while (!valid);

	list<Contract> historic = controller.getHistoric(client);
	if (historic.empty()) {
		cout << "The client has no contracts." << endl;
	}

	if (io_util::askBool("See the inactive clients again?"))
		run();
}

void ViewInactiveClientsUI::printClients(const vector<const Client *> &clients) const {
	cout << endl;
	for (unsigned long i = 0; i < clients.size(); ++i) {
		cout << i + 1 << ". ";
		clients[i]->print(cout);
	}
	cout << endl;
}
