#ifndef FEUP_AEDA_PROJ1_VEHICLE_LIST_H
#define FEUP_AEDA_PROJ1_VEHICLE_LIST_H


#include <vector>
#include "i_vehicle.h"

/*!
 * Manages a given set of vehicles stored in a container.
 */
class VehicleList {
public:

	/*!
	 * Creates a passenger vehicle with a given seat number.
	 *
	 * @param number_plate the number plate
	 * @param brand the brand
	 * @param model the model
	 * @param year the manufacturing year
	 * @param seat_number the seat number
	 * @return the reference to the created vehicle
	 */
	static IVehicle *build(const std::string &number_plate, const std::string &brand, const std::string &model,
						   unsigned year, unsigned seat_number);

	/*!
	 * Creates a commercial vehicle with a given cargo volume, max weight and refrigeration.
	 *
	 * @param number_plate the number plate
	 * @param brand the brand
	 * @param model the model
	 * @param year the manufacturing year
	 * @param cargo_volume the cargo volume
	 * @param max_weight the max weight
	 * @param is_refrigerated the bool that states if it is refrigerated
	 * @return the reference to the created vehicle
	 */
	static IVehicle *build(const std::string &number_plate, const std::string &brand, const std::string &model,
						   unsigned year, double cargo_volume, double max_weight, bool is_refrigerated);

	/*!
	 * Reads the vehicles from a file.
	 *
	 * @param params the vector of tokens to read
	 * @param the index of the starting token
	 */
	void read(const std::vector<std::string> &params, size_t first_element);

	/*!
	 * Adds a vehicle to the list.
	 *
	 * @param vehicle the pointer of the vehicle to add
	 * @return true if the vehicle was successfully added, false otherwise
	 */
	bool add(IVehicle *vehicle);

	/*!
	 * Removes a vehicle from the list.
	 *
	 * @param vehicle the vehicle equal to the one to remove
	 * @return true if the vehicle was successfully removed, false otherwise
	 */
	bool remove(const IVehicle &vehicle);

	/*!
	 * Gets the container with all vehicles immutable.
	 *
	 * @return the container with all vehicles
	 */
	const vector<IVehicle *> &getVehicles() const;

	/*!
	 * Gets a vehicle given a number plate.
	 *
	 * @param number_plate the number plate
	 * @return the vehicle
	 */
	IVehicle &get(const std::string &number_plate);

	/*!
	 * Verifies if a vehicle is valid, i.e., if it is possible to add it to the list.
	 *
	 * @param vehicle the vehicle to validate
	 * @return true if the vehicle is valid, false otherwise
	 */
	bool isValid(const IVehicle &vehicle) const;

	/*!
	 * Verifies if another vehicle list is equal to this one.
	 *
	 * @param rhs the other list
	 * @return true if they are equal, false otherwise
	 */
	bool operator==(const VehicleList &rhs) const;

	/*!
	 * Verifies if another vehicle list is different from this one.
	 *
	 * @param rhs the other list
	 * @return true if they are different, false otherwise
	 */
	bool operator!=(const VehicleList &rhs) const;

private:
	/*!
	 * The container that stores the vehicles
	 */
	std::vector<IVehicle *> vehicles;

	/*!
	 * Verifies if the list already has a vehicle.
	 *
	 * @param vehicle the vehicle to verify
	 * @return true if the list has the vehicle, false otherwise
	 */
	bool has(const IVehicle &vehicle) const;

	/*!
	 * Reads a single passenger vehicle.
	 *
	 * @param params the vector of tokens to read
	 * @param i the index of the first token to read
	 * @return the final index read
	 */
	size_t readPassengerVehicle(const vector<std::string> &params, size_t i);

	/*!
	 * Reads a single commercial vehicle.
	 *
	 * @param params the vector of tokens to read
 	 * @param i the index of the first token to read
	 * @return the final index read
	 */
	size_t readCommercialVehicle(const vector<std::string> &params, size_t i);
};


#endif //FEUP_AEDA_PROJ1_VEHICLE_LIST_H
