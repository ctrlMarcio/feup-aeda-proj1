#include "offer.h"

#include <utility>
#include <iostream>
#include "../../exception/invalid_schedule_exception.h"

Offer::Offer(IVehicle &vehicle, std::list<Schedule> available_schedules, IProvider &provider, float price) :
		vehicle(vehicle), available_schedules(std::move(available_schedules)), provider(provider), price(price) {}

void Offer::removeScheduleAvailability(const Schedule &to_remove) {
	for (auto it = available_schedules.begin(); it != available_schedules.end(); ++it) {
		if (to_remove.isInside(*it)) {
			try {
				Schedule before((*it).getBegin(), to_remove.getBegin());
				available_schedules.push_back(before);
			} catch (const InvalidScheduleException &e) {}

			try {
				Schedule after(to_remove.getEnd(), (*it).getEnd());
				available_schedules.push_back(after);
			} catch (const InvalidScheduleException &e) {}

			available_schedules.erase(it);
			break;
		}
	}
}

bool Offer::hasSchedule(const Schedule &schedule) const {
	for (const Schedule &s : available_schedules)
		if (schedule.isInside(s))
			return true;

	return false;
}

bool Offer::addSchedule(const Date &begin, const Date &end) {
	try {
		Schedule schedule(begin, end);
		available_schedules.push_back(schedule);

		return true;
	} catch (const std::logic_error &e) {
		return false;
	}
}

bool Offer::addSchedule(const Schedule &schedule) {
	for (const Schedule &s : available_schedules)
		if (schedule.interferesWith(s))
			return false;

	available_schedules.push_back(schedule);
	return true;
}

IVehicle &Offer::getVehicle() const {
	return vehicle;
}

std::ostream &operator<<(std::ostream &ostream, const Offer &offer) {
	ostream << "Vehicle: " << offer.vehicle << std::endl
			<< "Available schedules: " << std::endl;

	for (const Schedule &schedule : offer.available_schedules)
		ostream << schedule << std::endl;

	ostream << offer.provider << std::endl;
	ostream << "Price: " << offer.price;

	return ostream;
}

void Offer::setVehicle(const IVehicle &vehicle) {
	this->vehicle = vehicle;
}

void Offer::setAvailableSchedules(const std::list<Schedule> &available_schedules) {
	this->available_schedules = available_schedules;
}

bool Offer::setPrice(float price) {
	if (!isPriceValid(price))
		return false;
	this->price = price;
	return true;
}

bool Offer::operator==(const Offer &rhs) const {
	return vehicle == rhs.vehicle &&
		   available_schedules == rhs.available_schedules;
}

Offer &Offer::operator=(const Offer &offer) {
	this->vehicle = offer.vehicle;
	this->available_schedules = offer.available_schedules;
	this->price = offer.price;

	return *this;
}

float Offer::getPrice() const {
	return price;
}

const list<Schedule> &Offer::getAvailableSchedules() const {
	return available_schedules;
}

IProvider &Offer::getProvider() const {
	return provider;
}

bool Offer::isPriceValid(float price) {
	return price > 0;
}
