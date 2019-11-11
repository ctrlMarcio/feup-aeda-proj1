#include "ui_manager.h"

UIManager::UIManager(CurrentSession &current_session, Company &company) : current_session(current_session),
                                                                          company(company) {}

void UIManager::setCurrent(UI *ui) {
    current_ui = ui;
}

void UIManager::run() const {
    current_ui->run();
}
