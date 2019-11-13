#include "login_page_controller.h"
#include "../../../exception/invalid_login_exception.h"
#include "../../ui/admin/admin_page_ui.h"
#include "../../ui/client/client_page_ui.h"
#include "../../ui/company_client/company_client_page_ui.h"

LoginPageController::LoginPageController(CurrentSession &current_session, AuthUserManager &auth_user_manager,
                                         UIManager &ui_manager)
        : current_session(current_session), auth_user_manager(auth_user_manager), ui_manager(ui_manager) {}

bool LoginPageController::hasUser(const string &identification_number) {
    return auth_user_manager.has(identification_number);
}

bool LoginPageController::login(const string &identification_number, const string &password) {
    current_session.login(identification_number, password);
    return current_session.getUser().getIdentificationNumber() == identification_number;
}

void LoginPageController::redirect(const string &identification_number) {
    AuthUser &auth_user = auth_user_manager.getUser(identification_number);

    if (auth_user.getRole() == AuthUser::ADMIN_ROLE) {
        ui_manager.setCurrent(new AdminPageUI(ui_manager));
        ui_manager.run();
    } else if (auth_user.getRole() == AuthUser::CLIENT_ROLE) {
        ui_manager.setCurrent(new ClientPageUI(ui_manager));
        ui_manager.run();
    } else if (auth_user.getRole() == AuthUser::CLIENT_COMPANY_ROLE) {
        ui_manager.setCurrent(new CompanyClientPageUI(ui_manager));
        ui_manager.run();
    }
}
