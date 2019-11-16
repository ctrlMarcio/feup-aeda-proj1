#ifndef FEUP_AEDA_PROJ1_RENTAL_H
#define FEUP_AEDA_PROJ1_RENTAL_H


#include "../offer/offer.h"
#include "../schedule/schedule.h"

/*!
 * Represents a rental.
 * A rental is the process of renting a vehicle by a renter to a provider.
 */
class Rental {
public:
	/*!
	 * Constructs a rental given its offer, schedule and renter
	 *
	 * @param offer the reference to the offer
	 * @param schedule the schedule
	 * @param renter the user who rent
	 */
	Rental(Offer &offer, Schedule schedule, IRenter &renter);

	/*!
	 * Constructs a new rental given an offer, its start and end date.
	 * The dates will be used to construct a new schedule.
	 *
	 * @param offer the reference to the offer
	 * @param begin the start date
	 * @param end the end date
	 * @param renter the user who rent
	 */
	Rental(Offer &offer, const Date &begin, const Date &end, IRenter &renter);

	/*!
	 * Gets the offer of the rental
	 * @return the const reference to the offer
	 */
	const Offer &getOffer() const;

	/*!
	 * Gets the schedule of the rental.
	 *
	 * @return the const reference to the schedule
	 */
	const Schedule &getSchedule() const;

	/*!
	 * Gets the user who rented the vehicle.
	 *
	 * @return the renter
	 */
	IRenter &getRenter() const;

	/*!
	 * Gets the rental as a one line description.
	 *
	 * @return the description
	 */
	std::string toOneLineDescription() const;

	/*!
	 * Verifies if another rental is equal to this one.
	 *
	 * @param rhs the other rental
	 * @return true if they are equal, false otherwise
	 */
	bool operator==(const Rental &rhs) const;

	/*!
	 * Prints a rental in an ostream.
	 *
	 * @param ostream the ostream
	 * @param rental the rental to print
	 * @return the modified ostream
	 */
	friend ostream &operator<<(ostream &ostream, const Rental &rental);

private:
	const Offer &offer;

	const Schedule schedule;

	IRenter &renter;

	float price;

	float calculatePrice() const;
};


#endif //FEUP_AEDA_PROJ1_RENTAL_H
