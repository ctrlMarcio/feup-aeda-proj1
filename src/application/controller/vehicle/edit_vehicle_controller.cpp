#include "edit_vehicle_controller.h"

EditVehicleController::EditVehicleController(IProvider &provider, OfferManager &offer_manager) :
		provider(provider), offer_manager(offer_manager), vehicle_list(provider.getVehicleList()) {}

const vector<IVehicle *> &EditVehicleController::getVehicles() const {
	return vehicle_list.getVehicles();
}

void EditVehicleController::setVehicle(IVehicle *vehicle) {
	this->vehicle = vehicle;
}

bool EditVehicleController::isUpToRent() {
	if (vehicle == nullptr)
		return false;
	return offer_manager.hasOfferOf(*vehicle);
}

bool EditVehicleController::createOffer(const std::list<Schedule> &schedules, float price) {
	try {
		this->offer = OfferManager::build(*vehicle, schedules, provider, price);
	} catch (const std::exception &e) {
		return false;
	}

	return offer_manager.add(*offer);
}

bool EditVehicleController::removeOffer() {
	try {
		this->offer = &offer_manager.getOfferOf(*vehicle);
	} catch (const std::exception &e) {
		return false;
	}
	if (this->offer == nullptr)
		return false;

	return offer_manager.remove(*offer);
}

bool EditVehicleController::changePrice(float price) {
	return offer->setPrice(price);
}

void EditVehicleController::setOffer() {
	this->offer = &offer_manager.getOfferOf(*vehicle);
}

bool EditVehicleController::addSchedule(Schedule schedule) {
	return this->offer->addSchedule(schedule);
}
