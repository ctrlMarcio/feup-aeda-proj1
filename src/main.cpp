#include "util/date.h"
#include "model/company/company.h"
#include "auth/auth_user/auth_user_manager.h"
#include "auth/current_session/current_session.h"
#include "application/ui/ui_manager.h"
#include "application/ui/initial_page/initial_page_ui.h"

int main(int argc, char *argv[]) {
    AuthUserManager auth_user_manager;
    CurrentSession current_session(auth_user_manager);
    Company company("Google Ride+");

    UIManager ui_manager(current_session, auth_user_manager, company);
    ui_manager.setCurrent(new InitialPageUI(ui_manager));
    ui_manager.run();
}