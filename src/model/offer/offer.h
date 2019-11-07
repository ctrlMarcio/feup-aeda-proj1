#ifndef FEUP_AEDA_PROJ1_OFFER_H
#define FEUP_AEDA_PROJ1_OFFER_H


#include <ostream>
#include <model/vehicle/vehicle.h>

class Offer {
public:

	friend std::ostream &operator<<(std::ostream &ostream, const Offer &offer);

private:

	const Vehicle *vehicle;
};


#endif //FEUP_AEDA_PROJ1_OFFER_H
