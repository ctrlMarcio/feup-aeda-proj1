#ifndef FEUP_AEDA_PROJ1_VIEW_RENT_HISTORY_PAGE_UI_H
#define FEUP_AEDA_PROJ1_VIEW_RENT_HISTORY_PAGE_UI_H


#include "../ui.h"
#include "../ui_manager.h"

class ViewRentHistoryPageUI : public UI {
public:
    explicit ViewRentHistoryPageUI(UIManager &ui_manager);

    void run() override;

private:
    UIManager &ui_manager;
};


#endif //FEUP_AEDA_PROJ1_VIEW_RENT_HISTORY_PAGE_UI_H
