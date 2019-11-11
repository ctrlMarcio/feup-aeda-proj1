#include "rental.h"

#include <utility>

Rental::Rental(Offer &offer, Schedule schedule) : offer(offer), schedule(schedule) {
	this->price = this->calculatePrice();
}

Rental::Rental(Offer &offer, const Date &begin, const Date &end) :
		offer(offer), schedule(Schedule(begin, end)) {

	this->price = this->calculatePrice();
}

float Rental::calculatePrice() const {
	// TODO
	return 0;
}

const Offer &Rental::getOffer() const {
	return offer;
}

const Schedule &Rental::getSchedule() const {
	return schedule;
}
