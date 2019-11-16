#include "rental.h"

#include <utility>
#include <sstream>

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

bool Rental::operator==(const Rental &rhs) const {
	return offer == rhs.offer &&
		   schedule == rhs.schedule &&
		   price == rhs.price;
}

std::string Rental::toOneLineDescription() const {
	stringstream res_stream;

	res_stream << this->offer.getVehicle().getType();
	res_stream << "-" << this->offer.getVehicle().getBrand();
	res_stream << " " << this->offer.getVehicle().getModel();
	res_stream << " | " << this->schedule.getBegin().toString();
	res_stream << " to " << this->schedule.getEnd().toString();
	res_stream << " | id: " << this->offer.getProvider().getIdentificationNumber();
	res_stream << " | " + to_string(this->price) << " gbp";

	return res_stream.str();
}

ostream &operator<<(ostream &ostream, const Rental &rental) {
	ostream << rental.offer << endl << rental.schedule << endl << "Price: " << rental.price << "gbp" << endl;
	return ostream;
}
