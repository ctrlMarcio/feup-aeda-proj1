#include "offer.h"

std::ostream &operator<<(std::ostream &ostream, const Offer &offer) {
	// TODO
	ostream << *offer.vehicle;
	return ostream;
}
