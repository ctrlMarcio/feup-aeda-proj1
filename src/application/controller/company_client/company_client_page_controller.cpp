#include "company_client_page_controller.h"

CompanyClientPageController::CompanyClientPageController(CurrentSession &current_session) : current_session(
        current_session) {}

void CompanyClientPageController::logout() {
    current_session.logout();
}
