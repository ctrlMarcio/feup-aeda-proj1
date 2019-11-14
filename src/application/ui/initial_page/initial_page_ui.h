#ifndef FEUP_AEDA_PROJ1_INITIAL_PAGE_UI_H
#define FEUP_AEDA_PROJ1_INITIAL_PAGE_UI_H


#include "../ui.h"
#include "../ui_manager.h"
#include "../../controller/initial_page/initial_page_controller.h"
#include <iostream>
#include <sstream>
#include <iomanip>


using namespace std;


class InitialPageUI : public UI {
public:
    explicit InitialPageUI(UIManager &ui_manager);

    void run() override;

private:
    UIManager &ui_manager;

	InitialPageController controller;

    string options();

    char getOption();

    string singleOffer(int index);

	string exitMessage();
};


#endif //FEUP_AEDA_PROJ1_INITIAL_PAGE_UI_H
