#ifndef FEUP_AEDA_PROJ1_INVALID_DATE_EXCEPTION_H
#define FEUP_AEDA_PROJ1_INVALID_DATE_EXCEPTION_H


#include <stdexcept>
#include "../util/date.h"

/*!
 * Represents an exception of an invalid date.
 */
class InvalidDateException : public std::logic_error {
public:
    /*!
     * Establishes a new instance of InvalidDateException.
     *
     * @param date the date
     * @param message the message
     */
	explicit InvalidDateException(const Date &date = Date(1, 1, 1, 1, 1, 1), const std::string &message = "The date is invalid.");

    /*!
     * Establishes a new instance of InvalidDateException.
     *
     * @param message the message
     * @param date the date
     */
	explicit InvalidDateException(const std::string &message, const Date &date = Date(1, 1, 1, 1, 1, 1));

private:
    /*!
     * The date.
     */
	const Date date;

	/*!
	 * The message.
	 */
	const std::string message;
};


#endif //FEUP_AEDA_PROJ1_INVALID_DATE_EXCEPTION_H
