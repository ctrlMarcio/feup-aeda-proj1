#ifndef FEUP_AEDA_PROJ1_INVALID_SCHEDULE_EXCEPTION_H
#define FEUP_AEDA_PROJ1_INVALID_SCHEDULE_EXCEPTION_H


#include <stdexcept>


/*!
 * Represents an exception thrown when a bad schedule is created.
 */
class InvalidScheduleException : public std::logic_error {
public:
    /*!
     * Establishes a new instance of a InvalidScheduleException.
     * @param message
     */
	explicit InvalidScheduleException(const std::string &message = "The schedule is invalid.");

private:
    /*!
     * The message.
     */
	const std::string message;
};


#endif //FEUP_AEDA_PROJ1_INVALID_SCHEDULE_EXCEPTION_H
