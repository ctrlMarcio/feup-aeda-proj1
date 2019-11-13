#ifndef FEUP_AEDA_PROJ1_ADMIN_PAGE_UI_H
#define FEUP_AEDA_PROJ1_ADMIN_PAGE_UI_H


#include "../ui.h"
#include "../ui_manager.h"
#include "../../controller/admin/admin_page_controller.h"

class AdminPageUI : public UI {
public:
    explicit AdminPageUI(UIManager &ui_manager);

    void run() override;

private:
    UIManager &ui_manager;

    AdminPageController controller;

    string options();

    char getOption();
};


#endif //FEUP_AEDA_PROJ1_ADMIN_PAGE_UI_H
