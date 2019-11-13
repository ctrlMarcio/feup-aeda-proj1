#include "passenger_preference.h"

PassengerPreference::PassengerPreference(unsigned int min_year, unsigned int seat_number) :
		min_year(min_year), seat_number(seat_number) {}

unsigned int PassengerPreference::getMinYear() const {
	return min_year;
}

unsigned int PassengerPreference::getSeatNumber() const {
	return seat_number;
}
