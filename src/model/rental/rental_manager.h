#ifndef FEUP_AEDA_PROJ1_RENTAL_MANAGER_H
#define FEUP_AEDA_PROJ1_RENTAL_MANAGER_H


#include <list>
#include "rental.h"
#include "../offer/offer.h"
#include "../schedule/schedule.h"

class RentalManager {
public:
	static Rental createRental(Offer &offer, const Schedule &schedule);

	static Rental createRental(Offer &offer, const Date &begin, const Date &end);

	bool add(Rental rental);

	const std::list<Rental> &getAllRentals() const;

private:
	std::list<Rental> rentals;

	static bool isValid(const Rental &rental);
};


#endif //FEUP_AEDA_PROJ1_RENTAL_MANAGER_H
