#include <gtest/gtest.h>
#include <model/vehicle/vehicle_manager.h>
#include <model/vehicle/passenger_vehicle.h>

using testing::Eq;

TEST(vehicle_manager, get_maintained_vehicles) {
	VehicleManager manager;

	EXPECT_TRUE(manager.getMaintainedVehicles(10).empty());

	PassengerVehicle pv("a", "a", "a", 2000, 5);
	MaintainedVehicle mv1(pv, Date(21, 12, 2020));
	manager.addMaintainedVehicle(mv1);

	EXPECT_EQ(manager.getMaintainedVehicles(10).size(), 1);
	EXPECT_EQ(manager.getMaintainedVehicles(1)[0], mv1);
}

TEST(vehicle_manager, set_maintenance_day) {
	VehicleManager manager;

	EXPECT_TRUE(manager.getMaintainedVehicles(10).empty());

	PassengerVehicle pv("a", "a", "a", 2000, 5);
	MaintainedVehicle mv1(pv, Date(21, 12, 2020));
	MaintainedVehicle mv2(pv, Date(30, 12, 2020));
	manager.addMaintainedVehicle(mv1);

	Date new_date(10, 10, 2020);

	manager.setMaintenanceDay(mv1, new_date);
	EXPECT_EQ(manager.getMaintainedVehicles(1)[0].getMaintenanceDay(), new_date);
	EXPECT_FALSE(manager.setMaintenanceDay(mv2, new_date));
}