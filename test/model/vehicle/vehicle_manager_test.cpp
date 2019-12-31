#include <gtest/gtest.h>
#include <model/vehicle/vehicle_manager.h>
#include <model/vehicle/passenger_vehicle.h>
#include <exception/non_existent_vehicle_exception.h>

using testing::Eq;

TEST(vehicle_manager, get_maintained_vehicles) {
	VehicleManager manager;

	EXPECT_TRUE(manager.getMaintainedVehicles(10).empty());

	PassengerVehicle pv("a", "a", "a", 2000, 5);
	MaintainedVehicle mv1(pv, Date(21, 12, 2020));
	manager.addMaintainedVehicle(mv1);

	EXPECT_EQ(manager.getMaintainedVehicles(10).size(), 1);
	EXPECT_EQ(*manager.getMaintainedVehicles(1)[0], mv1);
}

TEST(vehicle_manager, set_maintenance_day_maintained_vehicle) {
	VehicleManager manager;

	EXPECT_TRUE(manager.getMaintainedVehicles(10).empty());

	PassengerVehicle pv1("a", "a", "a", 2000, 5);
	PassengerVehicle pv2("b", "b", "b", 2000, 5);
	MaintainedVehicle mv1(pv1, Date(21, 12, 2020));
	MaintainedVehicle mv2(pv1, Date(30, 12, 2020));
	MaintainedVehicle mv3(pv2, Date(30, 12, 2020));
	manager.addMaintainedVehicle(mv1);

	Date new_date(10, 10, 2020);

	manager.setMaintenanceDay(mv1, new_date);
	EXPECT_EQ(manager.getMaintainedVehicles(1)[0]->getMaintenanceDay(), new_date);
	manager.setMaintenanceDay(mv2, new_date);
	EXPECT_EQ(manager.getMaintainedVehicles(100).size(), 1);
	manager.setMaintenanceDay(mv3, new_date);
	EXPECT_EQ(manager.getMaintainedVehicles(100).size(), 2);
}

TEST(vehicle_manager, set_maintenance_day_vehicle) {
	VehicleManager manager;

	//EXPECT_TRUE(manager.getMaintainedVehicles(10).empty());

	PassengerVehicle pv1("a", "a", "a", 2000, 5);
	Date date1(21, 12, 2020);
	Date date2(30, 12, 2020);
	manager.setMaintenanceDay(pv1, date1);

	Date new_date(10, 10, 2020);

	manager.setMaintenanceDay(pv1, new_date);
	EXPECT_EQ(manager.getMaintainedVehicles(1)[0]->getMaintenanceDay(), new_date);
	manager.setMaintenanceDay(pv1, date2);
	EXPECT_EQ(manager.getMaintainedVehicles(100).size(), 1);
}

TEST(vehicle__manager, has_maintenance) {
	VehicleManager manager;

	PassengerVehicle pv("a", "a", "a", 2000, 5);
	MaintainedVehicle mv1(pv, Date(21, 12, 2020));

	EXPECT_FALSE(manager.hasMaintenance(pv));

	manager.addMaintainedVehicle(mv1);

	EXPECT_TRUE(manager.hasMaintenance(pv));
}

TEST(vehicle_manager, get_maintenance_day) {
	VehicleManager manager;

	PassengerVehicle pv("a", "a", "a", 2000, 5);
	Date date(21, 12, 20200);
	MaintainedVehicle mv1(pv, date);

	EXPECT_THROW(manager.getMaintenanceDay(pv), NonExistentVehicleException);

	manager.addMaintainedVehicle(mv1);

	EXPECT_EQ(manager.getMaintenanceDay(pv), date);

	manager.addMaintainedVehicle(mv1);
}
