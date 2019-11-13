#ifndef FEUP_AEDA_PROJ1_COMPANY_CLIENT_PAGE_UI_H
#define FEUP_AEDA_PROJ1_COMPANY_CLIENT_PAGE_UI_H


#include "../ui.h"
#include "../ui_manager.h"
#include "../../controller/company_client/company_client_page_controller.h"

class CompanyClientPageUI : public UI {
public:
    explicit CompanyClientPageUI(UIManager &ui_manager);

    void run() override;

private:
    UIManager &ui_manager;

    CompanyClientPageController controller;

    string options();

    char getOption();
};


#endif //FEUP_AEDA_PROJ1_COMPANY_CLIENT_PAGE_UI_H
