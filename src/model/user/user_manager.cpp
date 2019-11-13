#include "user_manager.h"

IProvider &UserManager::getProvider(const std::string &identification_number) const {
	// TODO add company (or admin)

	Client &client = client_manager.getClient(identification_number);
	IProvider *provider = &client;
	return *provider;
}

AdminManager &UserManager::getAdminManager() {
	return admin_manager;
}

ClientCompanyManager &UserManager::getClientCompanyManager() {
	return client_company_manager;
}

ClientManager &UserManager::getClientManager() {
	return client_manager;
}
