#ifndef FEUP_AEDA_PROJ1_RENTAL_MANAGER_H
#define FEUP_AEDA_PROJ1_RENTAL_MANAGER_H


#include <list>
#include "rental.h"
#include "../offer/offer.h"
#include "../schedule/schedule.h"
#include "../offer/offer_manager.h"

class RentalManager {
public:
	static Rental build(Offer &offer, const Schedule &schedule);

	static Rental build(Offer &offer, const Date &begin, const Date &end);

	bool add(Rental rental);

	/*!
	 * Reads the rentals from a file.
	 *
	 * @param directory the directory of the file. The file name is stored in the file_handling namespace
	 * @param offer_manager the offer manager to get the offers of
	 */
	void read(const std::string &directory, const OfferManager &offer_manager);

	/*!
	 * Writes the rentals to a file.
	 *
	 * @param directory the directory of the file. The directory should exist. The file name is stored in the file_handling namespace
	 */
	void write(const std::string &directory) const;

	const std::list<Rental> &getAllRentals() const;

private:
	std::list<Rental> rentals;

	static bool isValid(const Rental &rental);
};


#endif //FEUP_AEDA_PROJ1_RENTAL_MANAGER_H
