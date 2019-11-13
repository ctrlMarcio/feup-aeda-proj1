#include "login_page_controller.h"
#include "../../../exception/invalid_login_exception.h"

LoginPageController::LoginPageController(CurrentSession &current_session, AuthUserManager &auth_user_manager)
        : current_session(current_session), auth_user_manager(auth_user_manager) {}

bool LoginPageController::hasUser(const string &identification_number) {
    return auth_user_manager.has(identification_number);
}

bool LoginPageController::login(const string &identification_number, const string &password) {
    current_session.login(identification_number, password);
    return current_session.getUser().getIdentificationNumber() == identification_number;
}
