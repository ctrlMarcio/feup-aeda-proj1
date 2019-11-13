#ifndef FEUP_AEDA_PROJ1_COMPANY_CLIENT_PAGE_CONTROLLER_H
#define FEUP_AEDA_PROJ1_COMPANY_CLIENT_PAGE_CONTROLLER_H


#include "../../../auth/current_session/current_session.h"

class CompanyClientPageController {
public:
    explicit CompanyClientPageController(CurrentSession &current_session);

    void logout();
private:
    CurrentSession &current_session;
};


#endif //FEUP_AEDA_PROJ1_COMPANY_CLIENT_PAGE_CONTROLLER_H
