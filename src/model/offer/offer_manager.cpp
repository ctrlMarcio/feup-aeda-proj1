#include "../../exception/non_existent_offer_exception.h"
#include "offer_manager.h"
#include "../../application/io/file_handling.h"
#include "../../exception/invalid_file_exception.h"
#include "../../util/string_util.h"
#include <algorithm>
#include <fstream>

Offer OfferManager::build(IVehicle &vehicle, const std::list<Schedule> &available_schedules, IProvider &provider) {
	return Offer(vehicle, available_schedules, provider);
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

void OfferManager::read(const std::string &directory) {
	std::string file_path = "../../" + directory + "/" + file_handling::offer;

	ifstream ifstream;
	ifstream.open(file_path);

	if (!ifstream.is_open())
		throw InvalidFileException(file_path);

	std::string line;
	while (getline(ifstream, line)) {
		std::vector<std::string> params = string_util::split(line, file_handling::delimiter);

		std::string provider_id = params[0];
		std::string vehicle_plate = params[1];

		// TODO
		//IProvider &provider = get provider from somewhere(provider_id);
		//IVehicle &vehicle = provider.getVehicleList();

		float price = stof(params[2]);

		auto *schedules = new std::list<Schedule>;
		for (size_t i = 3; i < params.size(); ++i) {
			Date *begin = getDate(params[i]);
			Date *end = getDate(params[++i]);

			auto *schedule = new Schedule(*begin, *end);
			schedules->push_back(*schedule);
		}

		// TODO
		//Offer *offer = new Offer(vehicle, schedules, provider, price);
		//this->add(*offer);
	}

	ifstream.close();
}

void OfferManager::write(const std::string &directory) const {
	std::string file_path = "../../" + directory + "/" + file_handling::offer;

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
			printDate(ofstream, begin);
			ofstream << file_handling::delimiter;
			printDate(ofstream, end);
		}

		ofstream << std::endl;
	}

	ofstream.close();
}

Date *OfferManager::getDate(const std::string &date_string) const {
	vector<string> date_vector = string_util::split(date_string, file_handling::time_delimiter);
	int day = stoi(date_vector[0]);
	int month = stoi(date_vector[1]);
	int year = stoi(date_vector[2]);
	int hour = stoi(date_vector[3]);
	int minute = stoi(date_vector[4]);
	int second = stoi(date_vector[5]);

	return new Date(day, month, year, hour, minute, second);
}

void OfferManager::printDate(ofstream &ofstream, const Date &date) const {
	ofstream << date.getDay() << file_handling::time_delimiter <<
			 date.getMonth() << file_handling::time_delimiter <<
			 date.getYear() << file_handling::time_delimiter <<
			 date.getHour() << file_handling::time_delimiter <<
			 date.getMinute() << file_handling::time_delimiter <<
			 date.getSecond();
}