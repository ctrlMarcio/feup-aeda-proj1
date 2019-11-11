#ifndef FEUP_AEDA_PROJ1_INVALID_SCHEDULE_EXCEPTION_H
#define FEUP_AEDA_PROJ1_INVALID_SCHEDULE_EXCEPTION_H


#include <stdexcept>

class InvalidScheduleException : public std::logic_error {
public:
	explicit InvalidScheduleException(const std::string &message = "The schedule is invalid.");

private:
	const std::string message;
};


#endif //FEUP_AEDA_PROJ1_INVALID_SCHEDULE_EXCEPTION_H
