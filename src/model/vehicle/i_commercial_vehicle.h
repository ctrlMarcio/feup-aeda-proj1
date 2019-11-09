#ifndef FEUP_AEDA_PROJ1_I_COMMERCIAL_VEHICLE_H
#define FEUP_AEDA_PROJ1_I_COMMERCIAL_VEHICLE_H


#include "i_vehicle.h"


/*!
 * A ICommercialVehicle provides an implementation for a commercial vehicle that is characterized for having a cargo volume and max weight, and
 * for being refrigerated or not.
 * The ICommercialVehicle interface is a sub-interface of IVehicle.
 */
class ICommercialVehicle : public IVehicle {
public:
    /*!
     * Gets the cargo volume of this commercial vehicle. By convention the cargo volume should be in cubic meters.
     *
     * @return the cargo volume
     */
    virtual double getCargoVolume() const = 0;

    /*!
     * Gets the max weight of this commercial vehicle. By convention the max weight should be in kilograms.
     *
     * @return the max weight
     */
    virtual double getMaxWeight() const = 0;

    /*!
     * Returns whether the commercial vehicle is refrigerated or not.
     *
     * @return true, if the commercial vehicle is refrigerated. false, otherwise
     */
    virtual bool isRefrigerated() const = 0;

private:
	/*!
 	 * Compares to another commercial vehicle.
 	 *
 	 * @param vehicle the other vehicle
 	 * @return true if they are equal, false otherwise
 	 */
	virtual bool isEqual(const IVehicle &vehicle) const = 0;
};


#endif //FEUP_AEDA_PROJ1_I_COMMERCIAL_VEHICLE_H
