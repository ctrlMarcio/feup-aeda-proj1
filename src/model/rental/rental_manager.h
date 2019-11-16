#ifndef FEUP_AEDA_PROJ1_RENTAL_MANAGER_H
#define FEUP_AEDA_PROJ1_RENTAL_MANAGER_H


#include <list>
#include "rental.h"
#include "../offer/offer.h"
#include "../schedule/schedule.h"
#include "../offer/offer_manager.h"

/*!
 * Manages all the rents in a company.
 */
class RentalManager {
public:
	/*!
	 * Builds a rent.
	 *
	 * @param offer the offer of the rent
	 * @param schedule the schedule
	 * @param renter the user who rented
	 * @return the built rent
	 */
	static Rental build(Offer &offer, const Schedule &schedule, IRenter &renter);

	/*!
	 * Builds a rent.
	 *
	 * @param offer the offer
	 * @param begin the beginning date
	 * @param end the ending date
	 * @param renter the user who rent
	 * @return the built rent
	 */
	static Rental build(Offer &offer, const Date &begin, const Date &end, IRenter &renter);

	/*!
	 * Adds a rental to the manager.
	 *
	 * @param rental the rental to add
	 * @return if the rental was successfully added
	 */
	bool add(Rental rental);

	/*!
	 * Reads the rentals from a file.
	 *
	 * @param directory the directory of the file. The file name is stored in the file_handling namespace
	 * @param offer_manager the offer manager to get the offers of
	 * @param user_manager the user manager to get the author of the rentals
	 */
	void read(const std::string &directory, OfferManager &offer_manager, UserManager &user_Manager);

	/*!
	 * Writes the rentals to a file.
	 *
	 * @param directory the directory of the file. The directory should exist. The file name is stored in the file_handling namespace
	 */
	void write(const std::string &directory) const;

	/*!
	 * Gets the container with all the rentals.
	 *
	 * @return the container
	 */
	const std::list<Rental> &getAllRentals() const;

	/*!
	 * Gets the rentals for a specific user.
	 *
	 * @param identification_number the identification number
	 * @return the container
	 */
	std::vector<Rental *> getRentals(const string &identification_number);

private:
	/*!
	 * All the existent rentals.
	 */
	std::list<Rental> rentals;

	/*!
	 * Verifies if a rental is valid.
	 *
	 * @param rental the rental to verify
	 * @return true if the rental is valid, false otherwise
	 */
	bool isValid(const Rental &rental);
};


#endif //FEUP_AEDA_PROJ1_RENTAL_MANAGER_H
