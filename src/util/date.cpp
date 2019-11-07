#include <exception/invalid_date_exception.h>
#include <ctime>
#include "date.h"


Date::Date() {
	time_t now = time(nullptr);
	tm *ltm = localtime(&now);

	setYear(1900 + ltm->tm_year);
	setMonth(1 + ltm->tm_mon);
	setDay(ltm->tm_mday);
	setHour(ltm->tm_hour);
	setMinute(ltm->tm_min);
	setSecond(ltm->tm_sec);
}

Date::Date(int day, int month, int year, int hour, int minute, int second) {
	try {
		setYear(year);
		setMonth(month);
		setDay(day);
		setHour(hour);
		setMinute(minute);
		setSecond(second);
	} catch (InvalidDateException &e) {
		throw e;
	}
}

void Date::setDay(int day) {
	if (day < 1)
		throw InvalidDateException(std::to_string(day) + " is an incorrect day.");

	int tmp_month = (month >= 8) ? month + 1 : month;

	if (tmp_month % 2 == 1) {
		if (day > 31)
			throw InvalidDateException(std::to_string(day) + " is an incorrect day for the " + std::to_string(month) + ".");
	} else if (tmp_month == 2) {
		if ((isLeapYear() && day > 29) || (!isLeapYear() && day > 28))
			throw InvalidDateException(std::to_string(day) + " is an incorrect day for the " + std::to_string(month) + ".");
	} else if (day > 30) {
		throw InvalidDateException(std::to_string(day) + " is an incorrect day for the " + std::to_string(month) + ".");
	}

	this->day = day;
}

void Date::setMonth(int month) {
	if (month < 1 || month > 12)
		throw InvalidDateException(std::to_string(month) + " is an incorrect month.");
	this->month = month;
}

void Date::setYear(int year) {
	this->year = year;
}

void Date::setHour(int hour) {
	if (hour < 0 || hour > 23)
		throw InvalidDateException(std::to_string(hour) + " is an incorrect hour.");
	this->hour = hour;
}

void Date::setMinute(int minute) {
	if (minute < 0 || minute > 59)
		throw InvalidDateException(std::to_string(minute) + " is an incorrect minute.");
	this->minute = minute;
}

void Date::setSecond(int second) {
	if (second < 0 || second > 59)
		throw InvalidDateException(std::to_string(minute) + " is an incorrect minute.");
	this->second = second;
}

inline bool Date::isLeapYear() const {
	return ((this->year % 4 == 0 && this->year % 100 != 0) || this->year % 400 == 0);
}
