#include "register_page_controller.h"

RegisterPageController::RegisterPageController(AuthUserManager &auth_user_manager, Company &company)
        : auth_user_manager(auth_user_manager), company(company) {}

bool RegisterPageController::hasUser(const string &identification_number) {
    return auth_user_manager.has(identification_number);
}

bool RegisterPageController::createUser(const string &type, const string &name, const string &identification_number,
                                        const string &address) {
    AuthUser user = auth_user_manager.build(identification_number);
    if (type == "client") {
        Client client = company.getUserManager().getClientManager().build(name, identification_number, address);

        return auth_user_manager.add(user) && company.getUserManager().getClientManager().add(client);
    } else if (type == "company_client") {
        ClientCompany client_company = company.getUserManager().getClientCompanyManager().build(name, identification_number, address);

        return auth_user_manager.add(user) && company.getUserManager().getClientCompanyManager().add(client_company);
    }
    return false;
}

string RegisterPageController::getPassword(const string &identification_number) {
    return auth_user_manager.getUser(identification_number).getPassword();
}
