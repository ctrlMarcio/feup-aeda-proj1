#include "ui_manager.h"

UIManager::UIManager(CurrentSession &current_session, Company &company) : current_session(current_session),
                                                                          company(company) {}

void UIManager::setCurrent(UI *ui) {
    current_ui = ui;
}

void UIManager::run() const {
    current_ui->run();
}

Company &UIManager::getCompany() const {
    return company;
}

CurrentSession &UIManager::getCurrentSession() const {
    return current_session;
}

UI *UIManager::getCurrentUi() const {
    return current_ui;
}
