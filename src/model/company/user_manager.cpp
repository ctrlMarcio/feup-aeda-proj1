#include "user_manager.h"

void UserManager::read(const std::string &directory, VehicleList *vehicle_list) {
	admin_manager.read(directory);
	client_company_manager.read(directory);
	client_manager.read(directory);

	admin_manager.setVehicleList(vehicle_list);
}

void UserManager::write(const std::string &directory) {
	admin_manager.write(directory);
	client_company_manager.write(directory);
	client_manager.write(directory);
}

IProvider *UserManager::getProvider(const std::string &identification_number) {
	IProvider *provider;

	Admin *admin = admin_manager.get(identification_number);

	if (admin == nullptr) {
		Client *client = client_manager.get(identification_number);
		provider = client;
	} else {
		provider = admin;
	}
	return provider;
}

IRenter &UserManager::getRenter(const std::string &identification_number) {
	IRenter *renter;
	ClientCompany *cc = client_company_manager.get(identification_number);

	if (cc == nullptr) {
		Client *client = client_manager.get(identification_number);
		renter = client;
	} else {
		renter = cc;
	}

	return *renter;
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
