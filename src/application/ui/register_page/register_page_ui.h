#ifndef FEUP_AEDA_PROJ1_REGISTER_PAGE_UI_H
#define FEUP_AEDA_PROJ1_REGISTER_PAGE_UI_H


#include "../ui.h"
#include "../ui_manager.h"
#include "../../controller/register_page/register_page_controller.h"
#include <sstream>


class RegisterPageUI : public UI {
public:
    explicit RegisterPageUI(UIManager &ui_manager);

    void run() override;

private:
    UIManager &ui_manager;

    RegisterPageController controller;
};


#endif //FEUP_AEDA_PROJ1_REGISTER_PAGE_UI_H
