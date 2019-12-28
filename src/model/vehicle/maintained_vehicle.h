#ifndef FEUP_AEDA_PROJ1_MAINTAINED_VEHICLE_H
#define FEUP_AEDA_PROJ1_MAINTAINED_VEHICLE_H


#include "i_vehicle.h"
#include "../../util/date.h"

/*!
 * Stores the information about the maintenance day of a vehicle, storing a reference to the vehicle itself and a date.
 */
class MaintainedVehicle {
public:
	/*!
	 * The full default constructor.
	 *
	 * @param vehicle the vehicle
	 * @param maintenanceDay the maintenance day
	 */
	MaintainedVehicle(IVehicle &vehicle, const Date &maintenanceDay);

	/*!
	 * Sets the maintenance day of a vehicle, validating it first.
	 * For a day to be valid, it must be in the future. This is, starting from tomorrow.
	 *
	 * @param maintenance_day the new maintenance day
	 * @return true of the day was successfully set, false otherwise
	 */
	bool setMaintenanceDay(const Date &maintenance_day);

	const Date &getMaintenanceDay() const;

	IVehicle &getVehicle() const;

	/*!
	 * Compares two maintained vehicles taking into account the number of days left until its maintenance day.
	 * The less the number of days, bigger its priority, so
	 * E.g. 10 days left < 2 days left
	 *
	 * @param rhs the other maintained
	 * @return the maintained vehicle with less priority, this is, with more days left to maintenance
	 */
	bool operator<(const MaintainedVehicle &rhs) const;

	bool operator==(const MaintainedVehicle &rhs) const;

	MaintainedVehicle &operator=(const MaintainedVehicle &rhs);

private:
	/*!
	 * The reference to the vehicle.
	 */
	IVehicle &vehicle;

	/*!
	 * The date that marks the next maintenance day of the vehicle.
	 */
	Date maintenance_day;

	/*!
	 * Gets the number of days left to the next maintenance day of the vehicle.
	 *
	 * @return the number of days left
	 */
	unsigned daysLeft() const;
};


#endif //FEUP_AEDA_PROJ1_MAINTAINED_VEHICLE_H
