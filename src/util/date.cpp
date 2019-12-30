#include "../exception/invalid_date_exception.h"
#include <ctime>
#include <sstream>
#include <vector>
#include <fstream>
#include "date.h"
#include "string_util.h"
#include "../application/io/file_handling.h"

using namespace std;
using namespace string_util;

std::string Date::MONTH_NAMES[] = {"January",
								   "February",
								   "March",
								   "April",
								   "May",
								   "June",
								   "July",
								   "August",
								   "September",
								   "October",
								   "November",
								   "December"};

Date::Date() {
	time_t now = time(nullptr);
	tm *ltm = gmtime(&now);

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

Date *Date::getDate(const std::string &date_string) {
	vector<string> date_vector = string_util::split(date_string, file_handling::time_delimiter);
	int day = stoi(date_vector[0]);
	int month = stoi(date_vector[1]);
	int year = stoi(date_vector[2]);
	int hour = stoi(date_vector[3]);
	int minute = stoi(date_vector[4]);
	int second = stoi(date_vector[5]);

	return new Date(day, month, year, hour, minute, second);
}

void Date::printDateToFile(std::ofstream &ofstream, const Date &date) {
	ofstream << date.getDay() << file_handling::time_delimiter <<
			 date.getMonth() << file_handling::time_delimiter <<
			 date.getYear() << file_handling::time_delimiter <<
			 date.getHour() << file_handling::time_delimiter <<
			 date.getMinute() << file_handling::time_delimiter <<
			 date.getSecond();
}

inline bool Date::isLeapYear() const {
	return ((this->year % 4 == 0 && this->year % 100 != 0) || this->year % 400 == 0);
}

bool Date::operator>(const Date &date) const {
	return afterThan(date, false);
}

bool Date::operator<(const Date &date) const {
	return !afterThan(date, true);
}

bool Date::operator>=(const Date &date) const {
	return afterThan(date, true);
}

bool Date::operator<=(const Date &date) const {
	return !afterThan(date, false);
}

bool Date::afterThan(const Date &date, bool equal_to) const {
	if (this->year > date.year)
		return true;
	if (this->year < date.year)
		return false;
	if (this->month > date.month)
		return true;
	if (this->month < date.month)
		return false;
	if (this->day > date.day)
		return true;
	if (this->day < date.day)
		return false;
	if (this->hour > date.hour)
		return true;
	if (this->hour < date.hour)
		return false;
	if (this->minute > date.minute)
		return true;
	if (this->minute < date.minute)
		return false;
	if (this->second > date.second)
		return true;
	if (this->second < date.second)
		return false;

	return equal_to; // if they are equal
}

void Date::setDay(int day) {
	if (day < 1)
		throw InvalidDateException(std::to_string(day) + " is an incorrect day.");

	int tmp_month = (month >= 8) ? month + 1 : month;

	if (tmp_month % 2 == 1) {
		if (day > 31)
			throw InvalidDateException(
					std::to_string(day) + " is an incorrect day for the " + std::to_string(month) + ".");
	} else if (tmp_month == 2) {
		if ((isLeapYear() && day > 29) || (!isLeapYear() && day > 28))
			throw InvalidDateException(
					std::to_string(day) + " is an incorrect day for the " + std::to_string(month) + ".");
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

int Date::getDay() const {
	return day;
}

int Date::getMonth() const {
	return month;
}

int Date::getYear() const {
	return year;
}

int Date::getHour() const {
	return hour;
}

int Date::getMinute() const {
	return minute;
}

int Date::getSecond() const {
	return second;
}

std::string Date::getMonthName() const {
	return MONTH_NAMES[month - 1];
}

unsigned long Date::toJulianDay() const {
	int a = (14 - month) / 12;
	int y = year + 4800 - a;
	int m = month + 12 * a - 3;

	return day + (153 * m + 2) / 5 + y * 365 + y / 4 - 32083;
}

std::string Date::toString() const {
	std::stringstream string_stream;
	string_stream << pad_number(hour, 2) << ":" << pad_number(minute, 2) << ", " << day << " " << getMonthName() << " "
				  << year;
	return string_stream.str();
}

bool Date::operator==(const Date &rhs) const {
	return day == rhs.day &&
		   month == rhs.month &&
		   year == rhs.year &&
		   hour == rhs.hour &&
		   minute == rhs.minute &&
		   second == rhs.second;
}

std::ostream &operator<<(std::ostream &ostream, const Date &date) {
	ostream << pad_number(date.day, 2) << "/" << pad_number(date.month, 2) << "/" << date.year << " "
			<< pad_number(date.hour, 2) << ":" << pad_number(date.minute, 2) << "." << pad_number(date.second, 2);
	return ostream;
}

unsigned long Date::dayDifference(const Date &date1, const Date &date2) {
	Date sooner, later;

	if (date1 < date2) {
		sooner = date1;
		later = date2;
	} else {
		sooner = date2;
		later = date1;
	}

	return later.toJulianDay() - sooner.toJulianDay();
}

unsigned long Date::dayDifference(const Date &date) {
	return dayDifference(*this, date);
}

unsigned long Date::dayDifferenceInOrder(const Date &later, const Date &sooner) {
	return later.toJulianDay() - sooner.toJulianDay();
}

Date Date::addSecond() const {
	Date res = *this;

	try {
		res.setSecond(second + 1);
	} catch (InvalidDateException &e) {
		res.setSecond(0);
		res = res.addMinute();
	}

	return res;
}

Date Date::addMinute() const {
	Date res = *this;

	try {
		res.setMinute(minute + 1);
	} catch (InvalidDateException &e) {
		res.setMinute(0);
		res = res.addHour();
	}

	return res;
}

Date Date::addHour() const {
	Date res = *this;

	try {
		res.setHour(hour + 1);
	} catch (InvalidDateException &e) {
		res.setHour(0);
		res = res.addDay();
	}

	return res;
}

Date Date::addDay() const {
	Date res = *this;

	try {
		res.setDay(day + 1);
	} catch (InvalidDateException &e) {
		res.setDay(1);
		res = res.addMonth();
	}

	return res;
}

Date Date::addMonth() const {
	Date res = *this;

	try {
		res.setMonth(month + 1);
	} catch (InvalidDateException &e) {
		res.setMonth(1);
		res = res.addYear();
	}

	return res;
}

Date Date::addYear() const {
	Date res = *this;
	res.setYear(year + 1);
	return res;
}

Date Date::removeSecond() const {
	Date res = *this;

	try {
		res.setSecond(second - 1);
	} catch (InvalidDateException &e) {
		res.setSecond(59);
		res = res.removeMinute();
	}

	return res;
}

Date Date::removeMinute() const {
	Date res = *this;

	try {
		res.setMinute(minute - 1);
	} catch (InvalidDateException &e) {
		res.setMinute(59);
		res = res.removeHour();
	}

	return res;
}

Date Date::removeHour() const {
	Date res = *this;

	try {
		res.setHour(hour - 1);
	} catch (InvalidDateException &e) {
		res.setHour(23);
		res = res.removeDay();
	}

	return res;
}

Date Date::removeDay() const {
	Date res = *this;

	try {
		res.setDay(day - 1);
	} catch (InvalidDateException &e) { // day == 0
		res = res.removeMonth();

		int aux_day = 31;
		bool error;

		do {
			error = false;
			try {
				res.setDay(aux_day);
			} catch (InvalidDateException &e) {
				error = true;
			}
			aux_day--;
		} while (error);
	}

	return res;
}

Date Date::removeMonth() const {
	Date res = *this;

	try {
		res.setMonth(month - 1);
	} catch (InvalidDateException &e) {
		res.setMonth(12);
		res = res.removeYear();
	}

	return res;
}

Date Date::removeYear() const {
	Date res = *this;
	res.setYear(year - 1);
	return res;
}

void Date::printToFile(std::ofstream &ofstream) {
	Date::printDateToFile(ofstream, *this);
}
