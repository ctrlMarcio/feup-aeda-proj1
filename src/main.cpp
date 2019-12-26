#include "util/date.h"
#include "model/company/company.h"
#include "auth/auth_user/auth_user_manager.h"
#include "auth/current_session/current_session.h"
#include "application/ui/ui_manager.h"
#include "application/ui/initial_page/initial_page_ui.h"


int main(int argc, char *argv[]) {
	AuthUserManager auth_user_manager;
	CurrentSession current_session(auth_user_manager);
	Company company("FEUP Drive++");
	// TODO vehicle maintenance, this is, read and write, and update the maintenance date when it is reached

	string directory;

	if (argc == 2) {
		directory = argv[1];
		auth_user_manager.read(directory);
		company.read(directory);
	} else {
		directory = ".";
        auth_user_manager.read(directory);
		company.read(directory);
		cout << "\033[1;31mInvalid parameters, initializing without data.\033[0m" << endl;
	}

	UIManager ui_manager(current_session, auth_user_manager, company, directory);
	ui_manager.setCurrent(new InitialPageUI(ui_manager));
	ui_manager.run();
}