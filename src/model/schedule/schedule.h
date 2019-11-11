#ifndef FEUP_AEDA_PROJ1_SCHEDULE_H
#define FEUP_AEDA_PROJ1_SCHEDULE_H


#include "../../util/date.h"

class Schedule {
public:
	Schedule(const Date &begin, const Date &end);

	bool isInside(const Schedule &schedule) const;

	bool interfersWith(const Schedule &schedule) const;

	bool isInvalid() const;

	const Date &getBegin() const;

	const Date &getEnd() const;

	Schedule &operator=(const Schedule &schedule);

	/*!
	 * Verifies if another schedule is equal to this one.
	 *
	 * @param rhs the other schedule
	 * @return true if they are equal, false otherwise
	 */
	bool operator==(const Schedule &rhs) const;

private:
	Date begin;

	Date end;

	void setBegin(const Date &begin);

	void setEnd(const Date &end);
};


#endif //FEUP_AEDA_PROJ1_SCHEDULE_H
