#ifndef FEUP_AEDA_PROJ1_INVALID_DATE_EXCEPTION_H
#define FEUP_AEDA_PROJ1_INVALID_DATE_EXCEPTION_H


#include <stdexcept>
#include <util/date.h>

class InvalidDateException : public std::logic_error {
public:

	explicit InvalidDateException(const Date &date = Date(1, 1, 1, 1, 1, 1), const std::string &message = "The date is invalid.");

	explicit InvalidDateException(const std::string &message, const Date &date = Date(1, 1, 1, 1, 1, 1));

private:

	const Date date;

	const std::string message;
};


#endif //FEUP_AEDA_PROJ1_INVALID_DATE_EXCEPTION_H
