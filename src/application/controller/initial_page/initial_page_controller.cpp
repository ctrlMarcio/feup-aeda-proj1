#include "initial_page_controller.h"
#include "../../../exception/invalid_file_exception.h"

InitialPageController::InitialPageController(AuthUserManager &auth_user_manager, Company &company, const string &directory) :
		auth_user_manager(auth_user_manager),
		company(company),
		directory(directory) {}

void InitialPageController::save() {
	auth_user_manager.write(directory);
	company.write(directory);
}
