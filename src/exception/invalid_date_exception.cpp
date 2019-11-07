#include "invalid_date_exception.h"

InvalidDateException::InvalidDateException(const Date &date, const std::string &message) :
		std::logic_error(message), date(date), message(message) {}

InvalidDateException::InvalidDateException(const std::string &message, const Date &date) :
		std::logic_error(message), date(date), message(message) {}