#ifndef FEUP_AEDA_PROJ1_SCHEDULE_H
#define FEUP_AEDA_PROJ1_SCHEDULE_H


#include "../../util/date.h"

class Schedule {
public:
	Schedule(const Date &begin, const Date &end);

private:
	const Date begin;

	const Date end;
};


#endif //FEUP_AEDA_PROJ1_SCHEDULE_H
