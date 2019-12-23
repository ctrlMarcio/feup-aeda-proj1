#include "passenger_preference.h"

PassengerPreference::PassengerPreference(unsigned int min_year, unsigned int seat_number) :
		min_year(min_year), seat_number(seat_number) {}

unsigned int PassengerPreference::getMinYear() const {
	return min_year;
}

unsigned int PassengerPreference::getSeatNumber() const {
	return seat_number;
}

std::ostream &operator<<(std::ostream &ostream, const PassengerPreference &passenger_preference) {
	ostream << "Passenger preference:" << std::endl;
	ostream << "Minimum year: " << passenger_preference.min_year << std::endl;
	ostream << "Number of seats: " << passenger_preference.seat_number << std::endl;
	return ostream;
}

bool PassengerPreference::operator==(const PassengerPreference &rhs) const {
	return min_year == rhs.min_year &&
		   seat_number == rhs.seat_number;
}

bool PassengerPreference::operator!=(const PassengerPreference &rhs) const {
	return !(rhs == *this);
}
