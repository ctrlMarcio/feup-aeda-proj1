#ifndef FEUP_AEDA_PROJ1_DATE_H
#define FEUP_AEDA_PROJ1_DATE_H


#include <string>


class Date {
public:
	Date();

	Date(int day, int month, int year, int hour = 0, int minute = 0, int second = 0);

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
