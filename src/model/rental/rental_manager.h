#ifndef FEUP_AEDA_PROJ1_RENTAL_MANAGER_H
#define FEUP_AEDA_PROJ1_RENTAL_MANAGER_H


#include <list>
#include "rental.h"
#include "../offer/offer.h"
#include "../schedule/schedule.h"

class RentalManager {
public:
	static Rental createRental(Offer &offer, const Schedule &schedule);

	static bool isValid(const Rental &rental);

	bool add(Rental rental);

	const std::list<Rental> &getAllRentals() const;

private:
	std::list<Rental> rentals;
};


#endif //FEUP_AEDA_PROJ1_RENTAL_MANAGER_H
