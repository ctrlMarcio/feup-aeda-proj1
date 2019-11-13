#include "admin_page_controller.h"

AdminPageController::AdminPageController(CurrentSession &current_session) : current_session(current_session) {}

void AdminPageController::logout() {
    current_session.logout();
}
