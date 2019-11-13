#ifndef FEUP_AEDA_PROJ1_INITIAL_PAGE_UI_H
#define FEUP_AEDA_PROJ1_INITIAL_PAGE_UI_H


#include "../ui.h"
#include "../ui_manager.h"
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

    string options();

    char getOption();

    string singleOffer(int index);
};


#endif //FEUP_AEDA_PROJ1_INITIAL_PAGE_UI_H
