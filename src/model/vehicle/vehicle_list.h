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
	 * The destructor.
	 * Destructs every pointer in the container.
	 */
	~VehicleList();

	/*!
	 * Creates a passenger vehicle with a given seat number.
	 *
	 * @param seat_number the seat number
	 * @return the reference to the created vehicle
	 */
	IVehicle &createVehicle(unsigned seat_number) const;

	/*!
	 * Creates a commercial vehicle with a given cargo volume, max weight and refrigeration.
	 *
	 * @param cargo_volume the cargo volume
	 * @param max_weight the max weight
	 * @param is_refrigerated the bool that states if it is refrigerated
	 * @return the reference to the created vehicle
	 */
	IVehicle &createVehicle(double cargo_volume, double max_weight, bool is_refrigerated) const;

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

private:
	/*!
	 * The container that stores the vehicles
	 */
	std::vector<IVehicle *> vehicles;

	/*!
	 * Verifies if a vehicle is valid, i.e., if it is possible to add it to the list.
	 *
	 * @param vehicle the vehicle to validate
	 * @return true if the vehicle is valid, false otherwise
	 */
	bool isValid(const IVehicle &vehicle) const;

	/*!
	 * Verifies if the list already has a vehicle.
	 *
	 * @param vehicle the vehicle to verify
	 * @return true if the list has the vehicle, false otherwise
	 */
	bool has(const IVehicle &vehicle) const;
};


#endif //FEUP_AEDA_PROJ1_VEHICLE_LIST_H
