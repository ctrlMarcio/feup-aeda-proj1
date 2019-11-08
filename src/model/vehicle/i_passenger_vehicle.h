#ifndef FEUP_AEDA_PROJ1_I_PASSENGER_VEHICLE_H
#define FEUP_AEDA_PROJ1_I_PASSENGER_VEHICLE_H


#include "i_vehicle.h"


/*!
 * A IPassengerVehicle provides an implementation for a passenger vehicle that is characterized for having a seat number.
 * The IPassengerVehicle interface is a sub-interface of IVehicle.
 */
class IPassengerVehicle : public IVehicle {
public:
    /*!
     * Gets the seat number of this passenger vehicle.
     *
     * @return the seat number
     */
    virtual unsigned getSeatNumber() const = 0;
};


#endif //FEUP_AEDA_PROJ1_I_PASSENGER_VEHICLE_H
