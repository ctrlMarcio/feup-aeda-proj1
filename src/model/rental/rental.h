#ifndef FEUP_AEDA_PROJ1_RENTAL_H
#define FEUP_AEDA_PROJ1_RENTAL_H


#include "../offer/offer.h"
#include "../schedule/schedule.h"

class Rental {
public:
	Rental(Offer &offer, Schedule schedule);

	Rental(Offer &offer, const Date &begin, const Date &end);

	const Offer &getOffer() const;

	const Schedule &getSchedule() const;

private:
	const Offer &offer;

	const Schedule schedule;

	float price;

	float calculatePrice() const;
};


#endif //FEUP_AEDA_PROJ1_RENTAL_H
