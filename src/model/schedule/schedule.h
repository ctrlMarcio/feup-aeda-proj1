#ifndef FEUP_AEDA_PROJ1_SCHEDULE_H
#define FEUP_AEDA_PROJ1_SCHEDULE_H


#include "../../util/date.h"


/*!
 * Represents a schedule, characterized by a start and end date.
 */
class Schedule {
public:
    /*!
     * Establishes a new instance of a Schedule.
     *
     * @param begin the start date
     * @param end the end date
     */
	Schedule(const Date &begin, const Date &end);

	/*!
	 * Checks if a schedule is inside another.
	 * E.g.: 14h-15h is inside 13h-16h.
	 *
	 * @param schedule the other schedule
	 * @return true, if the schedule is inside another. false, otherwise
	 */
	bool isInside(const Schedule &schedule) const;

	/*!
	 * Checks if a schedule interferes with another.
	 * Two schedule interfere if one is partially, or completely, inside the other.
	 * E.g.: 13h-15h interferes with 14h-16h, 12h-16h, 12h-14h, 13h-15h, etc and does not with 11h-12h, 16h-17h, etc.
	 *
	 * @param schedule the other schedule
	 * @return true, if the schedule is inside another. false, otherwise
	 */
	bool interferesWith(const Schedule &schedule) const;

	/*!
	 * Gets a schedule that is a merge of this schedule with a given one.
	 * Simplified example: 	13h-15h merging with 14h-16h would return 13h-16h.
	 * 						14h-15h merging with 13h-16h would return 13h-16h.
	 * Note: "interferesWith" is called; if the schedules do not interfere, the result will be only the first schedule.
	 *
	 * @param schedule the given schedule to merge with
	 * @return the schedule that is the result of the merging
	 */
	Schedule mergeWith(const Schedule &schedule) const;

	/*!
	 * Checks if a schedule is valid or not.
	 * A schedule is invalid if the beginning date is after the ending date, or if it consists of only one "moment",
	 * this is, the beginning and the ending date is the same.
	 *
	 * @return true, if the schedule is valid. false, otherwise
	 */
	bool isInvalid() const;

	/*!
	 * Gets the start date.
	 *
	 * @return the start date
	 */
	const Date &getBegin() const;

	/*!
	 * Gets the end date.
	 *
	 * @return the end date
	 */
	const Date &getEnd() const;

	Schedule &operator=(const Schedule &schedule);

	/*!
	 * Verifies if another schedule is equal to this one.
	 * Two schedules are equal if their beginning and end is equal.
	 *
	 * @param rhs the other schedule
	 * @return true if they are equal, false otherwise
	 */
	bool operator==(const Schedule &rhs) const;

	/*!
	 * Sets the end date.
	 *
	 * @param end the end date
	 */
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
    /*!
     * The start date.
     */
	Date begin;

	/*!
	 * The end date.
	 */
	Date end;

	/*!
	 * Sets the start date.
	 *
	 * @param begin the start date
	 */
	void setBegin(const Date &begin);
};


#endif //FEUP_AEDA_PROJ1_SCHEDULE_H
