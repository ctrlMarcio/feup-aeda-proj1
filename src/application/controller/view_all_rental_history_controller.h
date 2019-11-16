#ifndef FEUP_AEDA_PROJ1_VIEW_ALL_RENTAL_HISTORY_CONTROLLER_H
#define FEUP_AEDA_PROJ1_VIEW_ALL_RENTAL_HISTORY_CONTROLLER_H


#include <list>
#include "../../model/rental/rental_manager.h"
#include "../../model/rental/rental.h"

class ViewAllRentalHistoryController {
public:
	explicit ViewAllRentalHistoryController(RentalManager &rental_manager);

	const std::list<Rental> &getAllRentals() const;

private:
	RentalManager &rental_manager;
};


#endif //FEUP_AEDA_PROJ1_VIEW_ALL_RENTAL_HISTORY_CONTROLLER_H
