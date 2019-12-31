#include "maintained_vehicle.h"
#include "../../exception/invalid_date_exception.h"

MaintainedVehicle::MaintainedVehicle(const MaintainedVehicle &maintained_vehicle)
		: vehicle(maintained_vehicle.getVehicle()), maintenance_day(maintained_vehicle.getMaintenanceDay()) {
}

MaintainedVehicle::MaintainedVehicle(IVehicle &vehicle, const Date &maintenanceDay) : vehicle(vehicle) {
	if (!setMaintenanceDay(maintenanceDay))
		throw InvalidDateException(maintenanceDay, "The maintenance date must be in the future.");
}

bool MaintainedVehicle::setMaintenanceDay(Date maintenance_day) {
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
	return vehicle == rhs.vehicle;
}

MaintainedVehicle &MaintainedVehicle::operator=(const MaintainedVehicle &rhs) {
	this->vehicle = rhs.vehicle;
	this->maintenance_day = rhs.maintenance_day;
	return *this;
}

const Date &MaintainedVehicle::getMaintenanceDay() const {
	return maintenance_day;
}

IVehicle &MaintainedVehicle::getVehicle() const {
	return vehicle;
}
