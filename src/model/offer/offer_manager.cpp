#include "../../exception/non_existent_offer_exception.h"
#include "offer_manager.h"
#include <algorithm>

Offer OfferManager::createOffer(IVehicle &vehicle, const std::list<Schedule> &available_schedules) {
	return Offer(vehicle, available_schedules);
}

std::vector<Offer *> OfferManager::getRecommendedOffers(const PreferenceList &preference_list) const {
	// TODO
	return std::vector<Offer *>();
}

bool OfferManager::hasOfferOf(const IVehicle &vehicle) const {
	for (const Offer &offer : offers)
		if (offer.getVehicle() == vehicle)
			return true;

	return false;
}

Offer &OfferManager::getOfferOf(const IVehicle &vehicle) {
	for (auto &offer : offers)
		if (offer.getVehicle() == vehicle)
			return offer;

	throw NonExistentOfferException();
}

bool OfferManager::add(const Offer &offer) {
	if (!this->isValid(offer))
		return false;

	offers.push_back(offer);
	return true;
}

bool OfferManager::remove(const Offer &offer) {
	bool removed = false;

	for (auto it = offers.begin(); it != offers.end(); ++it) {
		if (*it == offer) {
			offers.erase(it);
			removed = true;
			break;
		}
	}

	return removed;
}

vector<Offer> &OfferManager::getOffers() {
	return offers;
}

bool OfferManager::isValid(const Offer &offer) const {
	return std::find(offers.begin(), offers.end(), offer) == offers.end();
}
