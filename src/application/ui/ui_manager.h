#ifndef FEUP_AEDA_PROJ1_UI_MANAGER_H
#define FEUP_AEDA_PROJ1_UI_MANAGER_H


#include "ui.h"
#include "../../auth/current_session/current_session.h"
#include "../../model/company/company.h"

class UIManager {
public:
    UIManager(CurrentSession &current_session, Company &company);

    Company &getCompany() const;

    CurrentSession &getCurrentSession() const;

    UI *getCurrentUi() const;

    void setCurrent(UI *ui);

    void run() const;

private:
    Company &company;

    CurrentSession &current_session;

    UI *current_ui;
};


#endif //FEUP_{}AEDA_PROJ1_UI_MANAGER_H
