#include "offer.h"

#include <utility>

Offer::Offer(IVehicle &vehicle, std::list<Schedule> available_schedules) :
		vehicle(vehicle), available_schedules(std::move(available_schedules)) {}

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
