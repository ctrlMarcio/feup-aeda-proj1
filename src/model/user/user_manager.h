#ifndef FEUP_AEDA_PROJ1_USER_MANAGER_H
#define FEUP_AEDA_PROJ1_USER_MANAGER_H


#include "client_manager.h"
#include "admin_manager.h"
#include "client_company_manager.h"

class UserManager {
public:
	IProvider &getProvider(const std::string &identification_number) const;

	AdminManager &getAdminManager();

	ClientCompanyManager &getClientCompanyManager();

	ClientManager &getClientManager();

private:
	AdminManager admin_manager;

	ClientCompanyManager client_company_manager;

	ClientManager client_manager;
};


#endif //FEUP_AEDA_PROJ1_USER_MANAGER_H
