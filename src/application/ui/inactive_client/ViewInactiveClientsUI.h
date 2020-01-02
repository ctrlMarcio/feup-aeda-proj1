#ifndef FEUP_AEDA_PROJ1_VIEWINACTIVECLIENTSUI_H
#define FEUP_AEDA_PROJ1_VIEWINACTIVECLIENTSUI_H


#include "../ui.h"
#include "../ui_manager.h"
#include "../../controller/inactive_client/ViewInactiveClientsController.h"

class ViewInactiveClientsUI : public UI {
public:
	explicit ViewInactiveClientsUI(UIManager &ui_manager);

	void run() override;

private:
	ViewInactiveClientsController controller;

	void printClients(const vector<const Client *> &clients) const;
};


#endif //FEUP_AEDA_PROJ1_VIEWINACTIVECLIENTSUI_H
