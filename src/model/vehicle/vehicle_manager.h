#ifndef FEUP_AEDA_PROJ1_VEHICLE_MANAGER_H
#define FEUP_AEDA_PROJ1_VEHICLE_MANAGER_H


#include "vehicle_list.h"

/*!
 * Manages the vehicles in a company.
 */
class VehicleManager {
public:
    /*!
     * Reads the manager information based in a file in a specific a directory.
     *
     * @param directory the directory
     */
	void read(const std::string &directory);

	/*!
	 * Writes the manager information into a file in a specific directory.
	 *
	 * @param directory the directory
	 */
	void write(const std::string &directory);

	/*!
	 * Returns a const reference to the vehicle list.
	 *
	 * @return the reference to the vehicle list
	 */
	const VehicleList &getVehicleList() const;

	/*!
	 * Return the reference to the vehicle list.
	 *
	 * @return the reference to the vehicle list
	 */
	VehicleList &getVehicleList();

private:
    /*!
     * The vehicle list.
     */
	VehicleList vehicle_list;
};


#endif //FEUP_AEDA_PROJ1_VEHICLE_MANAGER_H
