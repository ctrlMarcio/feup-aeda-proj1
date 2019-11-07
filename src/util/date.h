#ifndef FEUP_AEDA_PROJ1_DATE_H
#define FEUP_AEDA_PROJ1_DATE_H


class Date {
public:

	Date();

	Date(int day, int month, int year, int hour = 0, int minute = 0, int second = 0);

	bool isLeapYear() const;

private:

	int day;

	int month;

	int year;

	int hour;

	int minute;

	int second;

	void setDay(int day);

	void setMonth(int month);

	void setYear(int year);

	void setHour(int hour);

	void setMinute(int minute);

	void setSecond(int second);
};


#endif //FEUP_AEDA_PROJ1_DATE_H
