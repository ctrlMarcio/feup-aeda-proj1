#include "non_existent_offer_exception.h"

#include <utility>

NonExistentOfferException::NonExistentOfferException(const std::string &message) :
		std::logic_error(message), message(message) {}
