#include "register_page_controller.h"

RegisterPageController::RegisterPageController(AuthUserManager &auth_user_manager, Company &company)
        : auth_user_manager(auth_user_manager), company(company) {}

bool RegisterPageController::hasUser(const string &identification_number) {
    return auth_user_manager.has(identification_number);
}

bool RegisterPageController::createUser(const string &type, const string &name, const string &identification_number,
                                        const string &address) {
    if (type == "client") {
        // TODO: Get both managers and create
        return true;
    } else if (type == "company_client") {
        // TODO: Get both managers and create
        return true;
    }
    return false;
}

string RegisterPageController::getPassword(const string &identification_number) {
    return auth_user_manager.getUser(identification_number).getPassword();
}
