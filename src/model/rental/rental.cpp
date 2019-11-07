#include "rental.h"

#include <utility>

Rental::Rental(Offer &offer, Schedule schedule) : offer(offer), schedule(std::move(schedule)) {}

float Rental::calculatePrice() const {
	// TODO
	return 0;
}

const Offer &Rental::getOffer() const {
	return offer;
}
