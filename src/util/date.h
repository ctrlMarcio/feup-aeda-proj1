#ifndef FEUP_AEDA_PROJ1_DATE_H
#define FEUP_AEDA_PROJ1_DATE_H


#include <string>


class Date {
public:
	Date();

	Date(int day, int month, int year, int hour = 0, int minute = 0, int second = 0);

	/*!
	 * Reads a date from a string.
	 * Used to read the files.
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

	bool isLeapYear() const;

	bool operator>(const Date &date) const;

	bool operator<(const Date &date) const;

	bool operator>=(const Date &date) const;

	bool operator<=(const Date &date) const;

    int getDay() const;

    int getMonth() const;

    int getYear() const;

    int getHour() const;

    int getMinute() const;

    int getSecond() const;

    std::string getMonthName() const;

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
    static std::string MONTH_NAMES[];

	int day;

	int month;

	int year;

	int hour;

	int minute;

	int second;

	bool afterThan(const Date &date, bool equal_to) const;

	void setDay(int day);

	void setMonth(int month);

	void setYear(int year);

	void setHour(int hour);

	void setMinute(int minute);

	void setSecond(int second);
};


#endif //FEUP_AEDA_PROJ1_DATE_H
