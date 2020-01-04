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
	 * Percentage of the money that goes to the company.
	 */
	constexpr static float COMPANY_PERCENTAGE = 30;

	/*!
	 * Constructs a rental given its offer, schedule and renter
	 *
	 * @param offer the reference to the offer
	 * @param schedule the schedule
	 * @param renter the user who rent
	 * @param celebration_date the celebration date of the rental
	 */
	Rental(Offer &offer, Schedule schedule, IRenter &renter, Date celebration_date = Date());

	/*!
	 * Constructs a new rental given an offer, its start and end date.
	 * The dates will be used to construct a new schedule.
	 *
	 * @param offer the reference to the offer
	 * @param begin the start date
	 * @param end the end date
	 * @param renter the user who rent
	 * @param celebration_date the celebration date of the rental
	 */
	Rental(Offer &offer, Date begin, Date end, IRenter &renter, Date celebration_date = Date());

	/*!
	 * Gets the offer of the rental
	 * @return the const reference to the offer
	 */
	const Offer &getOffer() const;

	/*!
	 * Gets the schedule of the rental.
	 *
	 * @return the reference to the schedule
	 */
	Schedule &getSchedule();

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

	const Date &getCelebrationDate() const;

	/*!
	 * Verifies if another rental is equal to this one.
	 * Two rentals are equal when the offer, the renter and the price is the same.
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
    /*!
     * The offer.
     */
	Offer offer;

	/*!
	 * The schedule.
	 */
	Schedule schedule;

	/*!
	 * The renter.
	 */
	IRenter &renter;

	/*!
	 * The price.
	 */
	float price;

	/*!
	 * The celebration date of the rental. I.e., the date at which the rental was made
	 */
	Date celebration_date;

	/*!
	 * Calculates the price of the rental taking into account the price of the offer and the company's percentage.
	 */
	float calculatePrice() const;
};


#endif //FEUP_AEDA_PROJ1_RENTAL_H
