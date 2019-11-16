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
	 *
	 * @param schedule the other schedule
	 * @return true, if the schedule is inside another. false, otherwise
	 */
	bool isInside(const Schedule &schedule) const;

    /*!
     * Checks if a schedule interferes with another.
     *
     * @param schedule the other schedule
     * @return true, if the schedule is inside another. false, otherwise
     */
	bool interferesWith(const Schedule &schedule) const;

	/*!
	 * Checks if a schedule is valid or not.
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
