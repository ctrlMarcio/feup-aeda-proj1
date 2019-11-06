#ifndef FEUP_AEDA_PROJ1_RENTAL_MANAGER_H
#define FEUP_AEDA_PROJ1_RENTAL_MANAGER_H


#include <list>
#include "rental.h"

class RentalManager {
public:

	const std::list<Rental> &getAllRentals() const;

private:

	std::list<Rental> rentals;
};


#endif //FEUP_AEDA_PROJ1_RENTAL_MANAGER_H
