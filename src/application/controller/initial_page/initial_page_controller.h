#ifndef FEUP_AEDA_PROJ1_INITIAL_PAGE_CONTROLLER_H
#define FEUP_AEDA_PROJ1_INITIAL_PAGE_CONTROLLER_H


#include "../../../auth/auth_user/auth_user_manager.h"
#include "../../../model/company/company.h"

class InitialPageController {
public:
	InitialPageController(AuthUserManager &auth_user_manager, Company &company, const string &directory);

	void save();

private:
	AuthUserManager &auth_user_manager;

	Company &company;

	const string &directory;
};


#endif //FEUP_AEDA_PROJ1_INITIAL_PAGE_CONTROLLER_H
