#ifndef FEUP_AEDA_PROJ1_RENTAL_H
#define FEUP_AEDA_PROJ1_RENTAL_H


#include "../offer/offer.h"
#include "../schedule/schedule.h"

class Rental {
public:
	Rental(Offer &offer, Schedule schedule);

	float calculatePrice() const;

	const Offer &getOffer() const;

private:
	const Offer &offer;

	const Schedule schedule;
};


#endif //FEUP_AEDA_PROJ1_RENTAL_H
