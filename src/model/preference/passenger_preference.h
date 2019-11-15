#ifndef FEUP_AEDA_PROJ1_PASSENGER_PREFERENCE_H
#define FEUP_AEDA_PROJ1_PASSENGER_PREFERENCE_H

#include <ostream>

/*!
 * Represents a preference to passenger vehicles.
 */
class PassengerPreference {
public:
	/*!
	 * Constructs a new passenger preference given its minimum year and seat number
	 *
	 * @param min_year the minimum year
	 * @param seat_number the seat number
	 */
	PassengerPreference(unsigned int min_year, unsigned int seat_number);

	/*!
	 * Gets the minimum year
	 *
	 * @return the minimum year
	 */
	unsigned int getMinYear() const;

	unsigned int getSeatNumber() const;

	friend std::ostream &operator<<(std::ostream &ostream, const PassengerPreference &passenger_preference);

private:
	unsigned min_year;

	unsigned seat_number;
};


#endif //FEUP_AEDA_PROJ1_PASSENGER_PREFERENCE_H
