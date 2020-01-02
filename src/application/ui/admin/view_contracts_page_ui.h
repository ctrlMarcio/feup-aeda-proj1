#ifndef FEUP_AEDA_PROJ1_VIEW_CONTRACTS_PAGE_UI_H
#define FEUP_AEDA_PROJ1_VIEW_CONTRACTS_PAGE_UI_H


#include "../ui_manager.h"
#include "../../controller/admin/view_contracts_page_controller.h"

class ViewContractsPageUI : public UI {
public:
    explicit ViewContractsPageUI(UIManager &ui_manager);

    void run() override;

private:
    UIManager &ui_manager;

    ViewContractsPageController controller;

    string getHeader();

    string getContracts();

    string getSortOption();

    string getSortField();
};


#endif //FEUP_AEDA_PROJ1_VIEW_CONTRACTS_PAGE_UI_H
