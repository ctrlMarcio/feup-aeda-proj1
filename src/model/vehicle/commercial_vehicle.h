#ifndef FEUP_AEDA_PROJ1_COMMERCIAL_VEHICLE_H
#define FEUP_AEDA_PROJ1_COMMERCIAL_VEHICLE_H


#include "i_vehicle.h"

/*!
 * A CommercialVehicle is an implementation of IVehicle that is characterized for having a cargo volume and max weight, and for being refrigerated
 * or not.
 */
class CommercialVehicle : public IVehicle {
public:
    const static string TYPE;

	/*!
	 * Establishes a new instance of a CommercialVehicle.
	 *
	 * @param number_plate the number plate
	 * @param brand the brand
	 * @param model the model
	 * @param year the year
	 * @param cargo_volume the cargo volume
	 * @param max_weight the max weight
	 * @param refrigerated the refrigeration type
	 */
	CommercialVehicle(string number_plate, string brand, string model, unsigned int year, double cargo_volume,
					  double max_weight, bool refrigerated);

	/*!
	 * Prints the vehicle information in a file.
	 *
	 * @param ofstream the ofstream of the file
	 */
	void printToFile(ofstream &ofstream) const override;

	/*!
	 * Prints the vehicle in an ostream.
	 *
	 * @param ostream the ostream
	 */
	void print(std::ostream &ostream) const override;

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
	 * Gets the number plate of this vehicle.
	 *
	 * @return the number plate
	 */
	const string &getNumberPlate() const override;

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
	unsigned int getYear() const override;

	/*!
	 * Returns the type of this vehicle.
	 *
	 * @return the type
	 */
	const string &getType() const override;

	/*!
	 * Verifies if this vehicle is equal to another one.
	 *
	 * @param rhs the other vehicle
	 * @return true if they are equal, false otherwise
	 */
	bool operator==(const CommercialVehicle &rhs) const;

private:
	/*!
	 * The number plate of this vehicle.
	 */
	string number_plate;

	/*!
	 * The brand of this vehicle.
	 */
	string brand;

	/*!
	 * The model of this vehicle.
	 */
	string model;

	/*!
	 * The year of this vehicle.
	 */
	unsigned int year;

	/*!
	 * The cargo volume of this vehicle.
	 */
	double cargo_volume;

	/*!
	 * The max weight of this vehicle.
	 */
	double max_weight;

	/*!
	 * The refrigeration type of this vehicle.
	 */
	bool refrigerated;

	/*!
	  * Compares to another commercial vehicle.
	  *
	  * @param vehicle the other vehicle
	  * @return true if they are equal, false otherwise
	  */
	bool isEqual(const IVehicle &vehicle) const override;
};


#endif //FEUP_AEDA_PROJ1_COMMERCIAL_VEHICLE_H
