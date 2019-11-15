#include "util/date.h"
#include "model/company/company.h"
#include "auth/auth_user/auth_user_manager.h"
#include "auth/current_session/current_session.h"
#include "application/ui/ui_manager.h"
#include "application/ui/initial_page/initial_page_ui.h"

/*!
 * \mainpage Rental and car sharing application
 *
 * This repository comprises the first part of the Algorithms and Data Structures course unit project.
 * The goal was to create a solution for a specific problem applying the object-oriented paradigm in C++.
 *
 * \section Project description
 * The theme approached in the problem is 'Fleet management and vehicle rental'.
 * Besides implementing a solution for the problem the software produced must have basic CRUD operations (create, read, update, delete),
 * file store handling and allow multiple listings of the data stored.
 */


int main(int argc, char *argv[]) {
	AuthUserManager auth_user_manager;
	CurrentSession current_session(auth_user_manager);
	Company company("Google Ride+");

	string directory;

	if (argc == 2) {
		directory = argv[1];
		auth_user_manager.read(directory);
		company.read(directory);
	} else {
		directory = "./";
		cout << "\033[1;31mInvalid parameters, initializing without data.\033[0m" << endl;
	}

	UIManager ui_manager(current_session, auth_user_manager, company, directory);
	ui_manager.setCurrent(new InitialPageUI(ui_manager));
	ui_manager.run();
}