#ifndef FEUP_AEDA_PROJ1_VEHICLE_MANAGER_H
#define FEUP_AEDA_PROJ1_VEHICLE_MANAGER_H


#include <queue>
#include "vehicle_list.h"
#include "maintained_vehicle.h"

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

	/*!
	 * Gets the next given amount of vehicles to whose maintenance is sooner.
	 *
	 * @param amount the amount of vehicles to get
	 * @return the vector of vehicles
	 * @return the vector of vehicles
	 */
	vector<MaintainedVehicle> getMaintainedVehicles(size_t amount);

	bool addMaintainedVehicle(const MaintainedVehicle &maintained_vehicle);

	/*!
	 * Verifies if a given vehicle has scheduled maintenance.
	 *
	 * @param vehicle the vehicle to verify
	 * @return true if the vehicle has maintenance, false otherwise
	 */
	bool hasMaintenance(const IVehicle &vehicle);

	/*!
	 * Removes the vehicles with the maintenance services already made from the queue.
	 */
	void update();

	/*!
	 * Gets the maintenance day of a given vehicle.
	 *
	 * @throw InvalidVehicleException if the vehicle has no maintenance scheduled
	 * @param vehicle the vehicle to get the maintenance day from
	 * @return the maintenance day
	 */
	Date getMaintenanceDay(const IVehicle &vehicle);

	/*!
	 * Changes the maintenance day of a given vehicle.
	 * This will change the priority queue.
	 * If the maintained vehicle does not exist, this is, if the vehicle has no maintenance schedule, adds it.
	 *
	 * @param maintained_vehicle the vehicle
	 * @param day the new day
	 */
	void setMaintenanceDay(MaintainedVehicle &maintained_vehicle, const Date &day);

	/*!
	 * Changes the maintenance day of a given vehicle.
	 * This will change the priority queue.
	 * If the maintained vehicles does not exist, this is, if the vehicle has no maintenance schedule, adds it.
	 *
	 * @param vehicle the vehicle
	 * @param date the new day
	 */
	void setMaintenanceDay(IVehicle &vehicle, const Date &date);

private:
    /*!
     * The vehicle list.
     */
	VehicleList vehicle_list;

	/*!
	 * The priority queues that order the vehicles by closeness to their maintenance day.
	 */
	priority_queue<MaintainedVehicle> maintained_vehicles;

	/*!
	 * Gets if the maintained vehicle exists.
	 *
	 * @param vehicle the maintained vehicle
	 * @return true if the vehicle exists, false otherwise
	 */
	bool hasMaintainedVehicle(const MaintainedVehicle &vehicle);
};


#endif //FEUP_AEDA_PROJ1_VEHICLE_MANAGER_H
