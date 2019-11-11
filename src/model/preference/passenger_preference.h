#ifndef FEUP_AEDA_PROJ1_PASSENGER_PREFERENCE_H
#define FEUP_AEDA_PROJ1_PASSENGER_PREFERENCE_H

class PassengerPreference {
public:
	PassengerPreference(unsigned int minYear, unsigned int qtSeats);

private:
	unsigned min_year;

	unsigned qt_seats;
};


#endif //FEUP_AEDA_PROJ1_PASSENGER_PREFERENCE_H
