#include "company.h"

#include <utility>
#include "../../exception/invalid_file_exception.h"

Company::Company(string name) : name(std::move(name)) {}

void Company::load(const std::string &directory) {
	try {
		user_manager.read(directory, &this->vehicleList);
		offer_manager.read(directory, user_manager);
		rental_manager.read(directory, offer_manager, user_manager);
	} catch (const InvalidFileException &e) {
		// TODO
	}
}

void Company::save(const std::string &directory) {
	try {
		user_manager.write(directory);
		offer_manager.write(directory);
		rental_manager.write(directory);
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
