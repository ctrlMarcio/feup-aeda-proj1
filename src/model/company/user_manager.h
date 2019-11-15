#ifndef FEUP_AEDA_PROJ1_USER_MANAGER_H
#define FEUP_AEDA_PROJ1_USER_MANAGER_H


#include "../../model/user/client_manager.h"
#include "../../model/user/admin_manager.h"
#include "../../model/user/client_company_manager.h"

class UserManager {
public:
	void read(const std::string &directory, VehicleList *vehicle_list);

	void write(const std::string &directory);

	IProvider *getProvider(const std::string &identification_number);

	IRenter &getRenter(const std::string &identification_number);

	AdminManager &getAdminManager();

	ClientCompanyManager &getClientCompanyManager();

	ClientManager &getClientManager();

private:
	AdminManager admin_manager;

	ClientCompanyManager client_company_manager;

	ClientManager client_manager;
};


#endif //FEUP_AEDA_PROJ1_USER_MANAGER_H
