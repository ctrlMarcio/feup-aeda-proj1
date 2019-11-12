#include <iosfwd>
#include "i_provider.h"


std::ostream &operator<<(std::ostream &ostream, const IProvider &provider) {
	provider.print(ostream);
	return ostream;
}
