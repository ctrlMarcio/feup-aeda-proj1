#ifndef FEUP_AEDA_PROJ1_NON_EXISTENT_OFFER_EXCEPTION_H
#define FEUP_AEDA_PROJ1_NON_EXISTENT_OFFER_EXCEPTION_H


#include <stdexcept>
#include "../model/offer/offer.h"

/*!
 * Represents an exception that states the non existence of an offer.
 */
class NonExistentOfferException : std::logic_error {
public:
	/*!
	 * Constructs the exception with and a message.
	 *
	 * @param message the message
	 */
	explicit NonExistentOfferException(const std::string &message = "The offer does not exist.");

private:
	/*!
	 * The message of the exception.
	 */
	std::string message;
};


#endif //FEUP_AEDA_PROJ1_NON_EXISTENT_OFFER_EXCEPTION_H
