#ifndef FEUP_AEDA_PROJ1_COMMERCIAL_VEHICLE_H
#define FEUP_AEDA_PROJ1_COMMERCIAL_VEHICLE_H


#include "i_vehicle.h"

/*!
 * A ICommercialVehicle provides an implementation for a commercial vehicle that is characterized for having a cargo volume and max weight, and
 * for being refrigerated or not.
 * The CommercialVehicle is a sub-class of IVehicle.
 */
class CommercialVehicle : public IVehicle {
public:
	/*!
	 * Constructs a new commercial vehicle.
	 * @param number_plate the number plate
	 * @param brand the brand
	 * @param model the model
	 * @param year the year
	 * @param cargo_volume the cargo volume
	 * @param max_weight the max weight
	 * @param is_refrigerated the bool that states if the vehicle is refrigerated or not
	 */
	CommercialVehicle(string number_plate, string brand, string model, unsigned int year, double cargo_volume, double max_weight, bool is_refrigerated);

	/*!
	 * The destructor of CommercialVehicle;
	 */
	~CommercialVehicle() override = default;

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
	 * Gets the cargo volume of this commercial vehicle. By convention the cargo volume should be in cubic meters.
	 *
	 * @return the cargo volume
	 */
	double getCargoVolume() const;

	/*!
	 * Gets the max weight of this commercial vehicle. By convention the max weight should be in kilograms.
	 *
	 * @return the max weight
	 */
	double getMaxWeight() const;

	/*!
	 * Returns whether the commercial vehicle is refrigerated or not.
	 *
	 * @return true, if the commercial vehicle is refrigerated. false, otherwise
	 */
	bool isRefrigerated() const;

	/*!
	 * Verifies if this commercial vehicle is equal to another one.
	 *
	 * @param rhs the another commercial vehicle
	 * @return true if they are equal, false otherwise
	 */
	bool operator==(const CommercialVehicle &rhs) const;

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
	 * The cargo volume of the vehicle.
	 */
	double cargo_volume;

	/*!
	 * The max weight the vehicle can carry.
	 */
	double max_weight;

	/*!
	 * The bool that sets if the vehicle is refrigerated or not.
	 */
	bool is_refrigerated;

	/*!
 	 * Compares to another commercial vehicle.
 	 *
 	 * @param vehicle the other vehicle
 	 * @return true if they are equal, false otherwise
 	 */
	bool isEqual(const IVehicle &vehicle) const override;
};


#endif //FEUP_AEDA_PROJ1_COMMERCIAL_VEHICLE_H
