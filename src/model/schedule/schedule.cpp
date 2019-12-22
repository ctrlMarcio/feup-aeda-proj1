#include <iostream>

#include "../../exception/invalid_schedule_exception.h"
#include "schedule.h"

Schedule::Schedule(const Date &begin, const Date &end) {
	setBegin(begin);
	setEnd(end);

	if (this->isInvalid())
		throw InvalidScheduleException();
}

Schedule &Schedule::operator=(const Schedule &schedule) {
	setBegin(schedule.begin);
	setEnd(schedule.end);

	return *this;
}

bool Schedule::isInside(const Schedule &schedule) const {
	return (this->begin >= schedule.begin && this->end <= schedule.end);
}

bool Schedule::isInvalid() const {
	return begin >= end;
}

bool Schedule::interferesWith(const Schedule &schedule) const {
	return !(schedule.end < this->begin || schedule.begin > this->end);
}

Schedule Schedule::mergeWith(const Schedule &schedule) const {
	if (!this->interferesWith(schedule))
		return *this;

	Date new_begin = (this->begin < schedule.begin) ? this->begin : schedule.begin; // gets the earliest begin
	Date new_end = (this->end > schedule.end) ? this->end : schedule.end; // gets the latest end

	return Schedule(new_begin, new_end);
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

bool Schedule::operator==(const Schedule &rhs) const {
	return begin == rhs.begin &&
		   end == rhs.end;
}

std::ostream &operator<<(std::ostream &ostream, const Schedule &schedule) {
	ostream << schedule.begin << " to " << schedule.end;
	return ostream;
}
