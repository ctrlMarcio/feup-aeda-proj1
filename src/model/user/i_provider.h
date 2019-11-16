#ifndef FEUP_AEDA_PROJ1_I_PROVIDER_H
#define FEUP_AEDA_PROJ1_I_PROVIDER_H


#include "../../model/vehicle/vehicle_list.h"
#include "i_user.h"

/*!
 * A IProvider provides the data implementation for the system providers. Derives from IUser.
 */
class IProvider : public IUser {
public:
    /*!
     * Gets the vehicle list of this provider.
     *
     * @return the vehicle list
     */
	virtual VehicleList &getVehicleList() = 0;

	/*!
	 * Prints the provider information given an output stream.
	 *
	 * @param ostream the ouput stream
	 */
	virtual void print(std::ostream &ostream) const = 0;

	/*!
	 * Output stream operator.
	 *
	 * @param ostream the output stream
	 * @param provider this provider
	 * @return the output stream
	 */
	friend std::ostream &operator<<(std::ostream &ostream, const IProvider &provider);
};


#endif //FEUP_AEDA_PROJ1_I_PROVIDER_H
