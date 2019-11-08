#include "schedule.h"

Schedule::Schedule(const Date &begin, const Date &end) {
	setBegin(begin);
	setEnd(end);
}

Schedule &Schedule::operator=(const Schedule &schedule) {
	setBegin(schedule.begin);
	setEnd(schedule.end);

	return *this;
}

bool Schedule::isInside(const Schedule &schedule) const {
	return (this->begin > schedule.begin && this->end < schedule.end);
}

bool Schedule::isInvalid() const {
	return begin >= end;
}

const Date &Schedule::getBegin() const {
	return begin;
}

const Date &Schedule::getEnd() const {
	return end;
}

void Schedule::setBegin(const Date &begin) {
	this->begin = begin;
}

void Schedule::setEnd(const Date &end) {
	this->end = end;
}
