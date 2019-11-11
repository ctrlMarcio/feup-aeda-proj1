#ifndef FEUP_AEDA_PROJ1_PASSENGER_VEHICLE_H
#define FEUP_AEDA_PROJ1_PASSENGER_VEHICLE_H

#include "i_vehicle.h"

/*!
 * A PassengerVehicle provides an implementation for a passenger vehicle that is characterized for having a seat number.
 * The PassengerVehicle is a sub-class of IVehicle.
 */
class PassengerVehicle : public IVehicle {
public:
	/*!
	 * Constructs a new passengers vehicle.
	 *
	 * @param number_plate the number plate
	 * @param brand the brand
	 * @param model the model
	 * @param year the manufacturing year
	 * @param seat_number the quantity of seats
	 */
	PassengerVehicle(string number_plate, string brand, string model, unsigned int year, unsigned int seat_number);

	/*!
 	 * Gets the number plate of this vehicle.
	 *
	 * @return the number plate
	 */
	const std::string &getNumberPlate() const override;

	/*!
 	 * Gets the brand of this vehicle.
 	 *
 	 * @return the brand
 	 */
	const string &getBrand() const override;

	/*!
 	 * Gets the model of this vehicle.
 	 *
 	 * @return the model
 	 */
	const string &getModel() const override;

	/*!
 	 * Gets the manufacturing year of this vehicle.
 	 *
 	 * @return the year
 	 */
	unsigned getYear() const override;

	/*!
	 * Gets the seat number of this passenger vehicle.
	 *
	 * @return the seat number
	 */
	unsigned getSeatNumber() const;

private:
	/*!
	 * The number plate of the vehicle.
	 */
	std::string number_plate;

	/*!
	 * The brand of the vehicle.
	 */
	std::string brand;

	/*!
	 * The model of the vehicle.
	 */
	std::string model;

	/*!
	 * The year of the vehicle.
	 */
	unsigned year;


	/*!
	 * The quantity of seats of the passenger vehicle.
	 */
	unsigned seat_number;

	/*!
	 * Compares to another passenger vehicle.
	 *
	 * @param vehicle the other vehicle
	 * @return true if they are equal, false otherwise
	 */
	bool isEqual(const IVehicle &vehicle) const override;
};


#endif //FEUP_AEDA_PROJ1_PASSENGER_VEHICLE_H
