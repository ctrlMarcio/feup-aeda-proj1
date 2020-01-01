#include "company.h"

#include <utility>
#include <fstream>
#include "../../exception/invalid_file_exception.h"

Company::Company(string name) : name(std::move(name)), contract_manager(rental_manager, offer_manager) {}

void Company::read(const std::string &directory) {
	try {
		user_manager.read(directory, &this->getVehicleManager().getVehicleList());
		vehicle_manager.read(directory);
		offer_manager.read(directory, user_manager);
		rental_manager.read(directory, offer_manager, user_manager);
		// TODO contract_manager.read(directory)
	} catch (const InvalidFileException &e) {
		// TODO
	}
}

void Company::write(const std::string &directory) {
	try {
		user_manager.write(directory);
		vehicle_manager.write(directory);
		offer_manager.write(directory);
		rental_manager.write(directory);
		// TODO contract_manager.read(directory)
	} catch (const InvalidFileException &e) {
		// TODO
	}
}

string Company::getName() const {
    return name;
}

UserManager &Company::getUserManager() {
	return user_manager;
}

RentalManager &Company::getRentalManager() {
	return rental_manager;
}

OfferManager &Company::getOfferManager() {
	return offer_manager;
}

VehicleManager &Company::getVehicleManager() {
	return vehicle_manager;
}

void Company::update() {
	this->vehicle_manager.update();
	this->user_manager.getClientManager().update(contract_manager);
}
