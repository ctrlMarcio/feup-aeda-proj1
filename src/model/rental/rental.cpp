#include "rental.h"

#include <utility>
#include <sstream>
#include <iomanip>

Rental::Rental(Offer &offer, Schedule schedule, IRenter &renter, Date celebration_date) :
		offer(offer), schedule(schedule), renter(renter), celebration_date(celebration_date) {
	this->price = this->calculatePrice();
}

Rental::Rental(Offer &offer, Date begin, Date end, IRenter &renter, Date celebration_date) :
		offer(offer), schedule(Schedule(begin, end)), renter(renter), celebration_date(celebration_date) {
	this->price = this->calculatePrice();
}

float Rental::calculatePrice() const {
	float provider_price = offer.getPrice() * (float) Date::dayDifference(schedule.getEnd(), schedule.getBegin());

	return provider_price + ((float) COMPANY_PERCENTAGE / 100) * provider_price;
}

const Offer &Rental::getOffer() const {
	return offer;
}

Schedule &Rental::getSchedule() {
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
	res_stream << " | " << std::fixed << std::setprecision(2) << price << " gbp";

	return res_stream.str();
}

ostream &operator<<(ostream &ostream, const Rental &rental) {
	ostream << rental.offer << endl << rental.schedule << endl << "Price: " << rental.price << "gbp" << endl;
	return ostream;
}

IRenter &Rental::getRenter() const {
	return renter;
}

const Date &Rental::getCelebrationDate() const {
	return celebration_date;
}
