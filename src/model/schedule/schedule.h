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

    void setEnd(const Date &end);

	/*!
	 * Prints a schedule in an ostream.
	 *
	 * @param ostream the ostream
	 * @param schedule the schedule
	 * @return the changed ostream
	 */
	friend std::ostream &operator<<(std::ostream &ostream, const Schedule &schedule);

private:
	Date begin;

	Date end;

	void setBegin(const Date &begin);
};


#endif //FEUP_AEDA_PROJ1_SCHEDULE_H
