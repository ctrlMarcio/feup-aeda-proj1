#ifndef FEUP_AEDA_PROJ1_LOGIN_PAGE_UI_H
#define FEUP_AEDA_PROJ1_LOGIN_PAGE_UI_H


#include "../ui.h"
#include "../ui_manager.h"
#include "../../controller/login_page/login_page_controller.h"


using namespace std;


class LoginPageUI : public UI {
public:
    explicit LoginPageUI(UIManager &ui_manager);

    void run() override;

private:
    UIManager &ui_manager;

    LoginPageController controller;

    string getHeader();

    string getIdentificationNumber();

    string getPassword();
};


#endif //FEUP_AEDA_PROJ1_LOGIN_PAGE_UI_H
