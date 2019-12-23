#ifndef FEUP_AEDA_PROJ1_DATE_H
#define FEUP_AEDA_PROJ1_DATE_H


#include <string>


/*!
 * The Date class represents a specific instant in time, with millisecond precision.
 */
class Date {
public:
    /*!
     * Establishes a new instance of a date, with the current time.
     */
	Date();

	/*!
	 * Establishes a new instance of a date, given its parameters.
	 *
	 * @param day the day
	 * @param month the month
	 * @param year the year
	 * @param hour the hour, default is 0
	 * @param minute the minute, default is 0
	 * @param second the second, default is 0
	 */
	Date(int day, int month, int year, int hour = 0, int minute = 0, int second = 0);

	/*!
	 * Reads a date from a string.
	 * Used to read the files.
	 * E.g.: "12.11.2019.12.21.43" should describe 12/12/2019 at 12H21m43s.
	 *
	 * @param date_vector the string of the date
	 * @return the pointer of the date
	 */
	static Date *getDate(const std::string &date_vector);

	/*!
	 * Prints a date to
	 * @param ofstream
	 * @param date
	 */
	static void printDate(std::ofstream &ofstream, const Date &date);

	/*!
	 * Returns whether the the year is a leap or not.
	 *
	 * @return true, if the year is leap. false, otherwise
	 */
	bool isLeapYear() const;

	/*!
	 * Returns whether a date is greater than another.
	 *
	 * @param date the date
	 * @return true, if this date is greater than the given one. false, otherwise
	 */
	bool operator>(const Date &date) const;

    /*!
     * Returns whether a date is less than another.
     *
     * @param date the date
     * @return true, if this date is less than the given one. false, otherwise
     */
	bool operator<(const Date &date) const;

    /*!
     * Returns whether a date is greater or equal than another.
     *
     * @param date the date
     * @return true, if this date is greater or equal than the given one. false, otherwise
     */
	bool operator>=(const Date &date) const;

    /*!
     * Returns whether a date is less or equal than another.
     *
     * @param date the date
     * @return true, if this date is less or equal than the given one. false, otherwise
     */
	bool operator<=(const Date &date) const;

	/*!
	 * Gets the day of this date.
	 *
	 * @return the day
	 */
    int getDay() const;

    /*!
     * Gets the month of this date.
     *
     * @return the month
     */
    int getMonth() const;

    /*!
     * Gets the year of this date.
     *
     * @return the year
     */
    int getYear() const;

    /*!
     * Gets the hour of this date.
     *
     * @return the hour
     */
    int getHour() const;

    /*!
     * Gets the minute of this date.
     *
     * @return the minute
     */
    int getMinute() const;

    /*!
     * Gets the second of this date.
     *
     * @return the second
     */
    int getSecond() const;

    /*!
     * Gets the month name of this date.
     *
     * @return the month name
     */
    std::string getMonthName() const;

	/*!
	 * Calculates the julian day of the date.
	 * https://en.wikipedia.org/wiki/Julian_day for more information on the julian day.
	 * The conversion is made in O(1) to ease day operations.
	 * Source: https://stason.org/TULARC/society/calendars/2-15-1-Is-there-a-formula-for-calculating-the-Julian-day-nu.html
	 *
	 * @return the corresponding julian day
	 */
	unsigned long toJulianDay() const;

	/*!
	 * Calculates the difference in days from two dates.
	 * The calculation is made using julian days, using the "toJulianDay" function.
	 * E.g.: 21-dez-2019 23h59 to 22-dez-2019 00h02 would return 1 day of difference.
	 *
	 * @param date1 the later date
	 * @param date2 the sooner date
	 * @return the difference in hours
	 */
	static unsigned long dayDifference(const Date &later, const Date &sooner);

    /*!
     * Gets a text representation of the date.
     *
     * @return a text representation
     */
    std::string toString() const;

	/*!
	 * Verifies if another date is equal to this one.
	 *
	 * @param rhs the other date
	 * @return true if they are equal, false otherwise
	 */
	bool operator==(const Date &rhs) const;

	/*!
	 * Prints a date in an ostream.
	 *
	 * @param ostream the ostream
	 * @param date the date
	 * @return the changed ostream
	 */
	friend std::ostream &operator<<(std::ostream &ostream, const Date &date);

private:
    /*!
     * The month names.
     */
    static std::string MONTH_NAMES[];

    /*!
     * The day of this date.
     */
	int day;

    /*!
     * The month of this date.
     */
	int month;

    /*!
     * The year of this date.
     */
	int year;

    /*!
     * The hour of this date.
     */
	int hour;

    /*!
     * The minute of this date.
     */
	int minute;

    /*!
     * The second of this date.
     */
	int second;

	/*!
	 * Returns whether a date is after another.
	 *
	 * @param date the date to compare
	 * @param equal_to the equal comparison
	 * @return true, if this date is after than the other. false, otherwise
	 */
	bool afterThan(const Date &date, bool equal_to) const;

	/*!
	 * Sets the day of the date.
	 *
	 * @param day the day
	 */
	void setDay(int day);

    /*!
	 * Sets the month of the date.
	 *
	 * @param month the month
	 */
	void setMonth(int month);

    /*!
     * Sets the year of the date.
     *
     * @param year the year
     */
	void setYear(int year);

    /*!
     * Sets the hour of the date.
     *
     * @param hour the hour
     */
	void setHour(int hour);

    /*!
     * Sets the minute of the date.
     *
     * @param minute the minute
     */
	void setMinute(int minute);

    /*!
     * Sets the second of the date.
     *
     * @param second the second
     */
	void setSecond(int second);
};


#endif //FEUP_AEDA_PROJ1_DATE_H
