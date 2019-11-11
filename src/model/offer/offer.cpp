#include "offer.h"

#include <utility>
#include "../../exception/invalid_schedule_exception.h"

Offer::Offer(IVehicle &vehicle, std::list<Schedule> available_schedules, float price) :
		vehicle(vehicle), available_schedules(std::move(available_schedules)), price(price) {}

void Offer::removeScheduleAvailability(const Schedule &to_remove) {
	for (auto it = available_schedules.begin(); it != available_schedules.end(); ++it) {
		if (to_remove.isInside(*it)) {
			Schedule before((*it).getBegin(), to_remove.getBegin());
			Schedule after(to_remove.getEnd(), (*it).getEnd());

			if (!before.isInvalid())
				available_schedules.push_back(before);
			if (!after.isInvalid())
				available_schedules.push_back(after);

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
		if (schedule.interfersWith(s))
			return false;

	available_schedules.push_back(schedule);
	return true;
}

IVehicle &Offer::getVehicle() const {
	return vehicle;
}

std::ostream &operator<<(std::ostream &ostream, const Offer &offer) {
	// TODO
	return ostream;
}

void Offer::setVehicle(const IVehicle &vehicle) {
	this->vehicle = vehicle;
}

void Offer::setAvailableSchedules(const std::list<Schedule> &available_schedules) {
	this->available_schedules = available_schedules;
}

void Offer::setPrice(float price) {
	this->price = price;
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
