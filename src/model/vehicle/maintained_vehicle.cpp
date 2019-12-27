#include "maintained_vehicle.h"
#include "../../exception/invalid_date_exception.h"

MaintainedVehicle::MaintainedVehicle(IVehicle &vehicle, const Date &maintenanceDay) : vehicle(vehicle) {
	if (!setMaintenanceDay(maintenanceDay))
		throw InvalidDateException(maintenanceDay, "The maintenance date must be in the future.");
}

bool MaintainedVehicle::setMaintenanceDay(const Date &maintenance_day) {
	Date now;

	if (maintenance_day <= now)
		return false;

	this->maintenance_day = maintenance_day;
	return true;
}

unsigned MaintainedVehicle::daysLeft() const {
	Date now;
	return now.dayDifference(maintenance_day);
}

bool MaintainedVehicle::operator<(const MaintainedVehicle &rhs) const {
	return this->daysLeft() > rhs.daysLeft(); // > so the priority queue in VehicleManager is a min heap
}

bool MaintainedVehicle::operator==(const MaintainedVehicle &rhs) const {
	return vehicle == rhs.vehicle &&
		   maintenance_day.getDay() == rhs.maintenance_day.getDay() &&
		   maintenance_day.getMonth() == maintenance_day.getMonth() &&
		   maintenance_day.getYear() == maintenance_day.getYear();
}

MaintainedVehicle &MaintainedVehicle::operator=(const MaintainedVehicle &rhs) {
	if (this == &rhs)
		return *this;

	this->vehicle = rhs.vehicle;
	this->maintenance_day = rhs.maintenance_day;
	return *this;
}

const Date &MaintainedVehicle::getMaintenanceDay() const {
	return maintenance_day;
}
