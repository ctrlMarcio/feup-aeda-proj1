#include "client_page_controller.h"

ClientPageController::ClientPageController(CurrentSession &current_session) : current_session(current_session) {}

void ClientPageController::logout() {
    current_session.logout();
}
