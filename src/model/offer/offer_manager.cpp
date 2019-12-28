#include "../../exception/non_existent_offer_exception.h"
#include "offer_manager.h"
#include "../../application/io/file_handling.h"
#include "../../exception/invalid_file_exception.h"
#include "../../util/string_util.h"
#include "../vehicle/passenger_vehicle.h"
#include "../vehicle/commercial_vehicle.h"
#include <algorithm>
#include <fstream>

Offer *OfferManager::build(IVehicle &vehicle, const std::list<Schedule> &available_schedules, IProvider &provider, float price) {
	return new Offer(vehicle, available_schedules, provider, price);
}

std::vector<Offer *> OfferManager::getRecommendedOffers(const PreferenceList &preference_list) {
	std::vector<Offer *> rec_offers;

	PassengerPreference *pp = preference_list.getPassengerPreference();
	CommercialPreference *cp = preference_list.getCommercialPreference();

	for (Offer &offer : offers) {
		IVehicle &vehicle = offer.getVehicle();

		const string &type = vehicle.getType();
		if (type == PassengerVehicle::TYPE && pp != nullptr) {
			auto &pv = dynamic_cast<PassengerVehicle &>(vehicle);

			if (pp->getMinYear() <= pv.getYear() && pp->getSeatNumber() == pv.getSeatNumber())
				rec_offers.push_back(&offer);

		} else if (type == CommercialVehicle::TYPE && cp != nullptr) {
			auto &cv = dynamic_cast<CommercialVehicle &>(vehicle);

			if (cp->getMinYear() <= cv.getYear() && cp->isRefrigerated() == cv.isRefrigerated() &&
				cp->getMinMaxWeight() <= cv.getMaxWeight() && cp->getCargoVolume() <= cv.getCargoVolume())
				rec_offers.push_back(&offer);
		}
	}

	return rec_offers;
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

void OfferManager::read(const std::string &directory, UserManager &user_manager) {
	std::string file_path = directory + "/" + file_handling::offer;

	ifstream ifstream;
	ifstream.open(file_path);

	if (!ifstream.is_open())
		throw InvalidFileException(file_path);

	std::string line;
	while (getline(ifstream, line)) {
		std::vector<std::string> params = string_util::split(line, file_handling::delimiter);

		std::string provider_id = params[0];
		IProvider &provider = *user_manager.getProvider(provider_id);

		std::string vehicle_plate = params[1];
		IVehicle &vehicle = provider.getVehicleList().get(vehicle_plate);

		float price = stof(params[2]);

		auto *schedules = new std::list<Schedule>;
		for (size_t i = 3; i < params.size(); ++i) {
			Date *begin = Date::getDate(params[i]);
			Date *end = Date::getDate(params[++i]);

			auto *schedule = new Schedule(*begin, *end);
			schedules->push_back(*schedule);
		}

		auto *offer = new Offer(vehicle, *schedules, provider, price);
		this->add(*offer);
	}

	ifstream.close();
}

void OfferManager::write(const std::string &directory) const {
	std::string file_path = directory + "/" + file_handling::offer;

	ofstream ofstream;
	ofstream.open(file_path);

	if (!ofstream.is_open())
		throw InvalidFileException(file_path);

	for (const Offer &offer : offers) {
		ofstream << offer.getProvider().getIdentificationNumber() << file_handling::delimiter << offer.getVehicle().getNumberPlate() << file_handling::delimiter <<
				 to_string(offer.getPrice());

		for (const Schedule &schedule : offer.getAvailableSchedules()) {
			const Date &begin = schedule.getBegin();
			const Date &end = schedule.getEnd();

			ofstream << file_handling::delimiter;
			Date::printDate(ofstream, begin);
			ofstream << file_handling::delimiter;
			Date::printDate(ofstream, end);
		}

		ofstream << std::endl;
	}

	ofstream.close();
}

void OfferManager::removeDay(const IVehicle &vehicle, const Date &date) {
	Date begin(date.getDay(), date.getMonth(), date.getYear(), 0, 0, 0);
	Date end(date.getDay(), date.getMonth(), date.getYear(), 23, 59, 59);
	Schedule to_remove(begin, end);

	for (Offer &offer : offers) {
		if (offer.getVehicle() == vehicle) {
			offer.removeScheduleAvailability(to_remove);
		}
	}
}
