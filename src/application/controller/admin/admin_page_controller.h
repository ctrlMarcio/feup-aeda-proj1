#ifndef FEUP_AEDA_PROJ1_ADMIN_PAGE_CONTROLLER_H
#define FEUP_AEDA_PROJ1_ADMIN_PAGE_CONTROLLER_H


#include "../../../auth/current_session/current_session.h"

class AdminPageController {
public:
    explicit AdminPageController(CurrentSession &current_session);

    void logout();
private:
    CurrentSession &current_session;
};


#endif //FEUP_AEDA_PROJ1_ADMIN_PAGE_CONTROLLER_H
