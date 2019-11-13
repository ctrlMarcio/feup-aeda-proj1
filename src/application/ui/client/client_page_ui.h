#ifndef FEUP_AEDA_PROJ1_CLIENT_PAGE_UI_H
#define FEUP_AEDA_PROJ1_CLIENT_PAGE_UI_H


#include "../ui.h"
#include "../ui_manager.h"
#include "../../controller/client/client_page_controller.h"

class ClientPageUI : public UI {
public:
    explicit ClientPageUI(UIManager &ui_manager);

    void run() override;

private:
    UIManager &ui_manager;

    ClientPageController controller;

    string options();

    char getOption();
};


#endif //FEUP_AEDA_PROJ1_CLIENT_PAGE_UI_H
