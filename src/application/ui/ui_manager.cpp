#include "ui_manager.h"

#include <utility>

UIManager::UIManager(CurrentSession &current_session, AuthUserManager &auth_user_manager, Company &company, string directory)
		: current_session(current_session),
		  auth_user_manager(auth_user_manager),
		  company(company),
		  directory(std::move(directory)) {}

void UIManager::setCurrent(UI *ui) {
	current_ui = ui;
}

void UIManager::run() const {
	current_ui->run();
}

Company &UIManager::getCompany() const {
	return company;
}

AuthUserManager &UIManager::getAuthUserManager() const {
	return auth_user_manager;
}

string &UIManager::getDirectory() {
	return directory;
}

CurrentSession &UIManager::getCurrentSession() const {
	return current_session;
}

UI *UIManager::getCurrentUI() const {
	return current_ui;
}
