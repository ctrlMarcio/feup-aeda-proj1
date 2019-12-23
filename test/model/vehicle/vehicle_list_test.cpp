#include <gtest/gtest.h>
#include <model/vehicle/passenger_vehicle.h>
#include <model/vehicle/vehicle_list.h>
#include <exception/non_existent_vehicle_exception.h>

using testing::Eq;

TEST(vehicle_list, build) {
	IVehicle *vehicle = new PassengerVehicle("1", "1", "1", 2001, 1);

	ASSERT_EQ(VehicleList::build("1", "1", "1", 2001, 1), *vehicle);
}

TEST(vehicle_list, add) {
	VehicleList manager;

	IVehicle *vehicle1 = new PassengerVehicle("1", "1", "1", 2001, 1);
	IVehicle *vehicle2 = new PassengerVehicle("2", "2", "2", 2002, 2);

	ASSERT_TRUE(manager.add(vehicle1));

	ASSERT_FALSE(manager.add(vehicle1));
	ASSERT_TRUE(manager.add(vehicle2));

	ASSERT_FALSE(manager.add(vehicle2));
}

TEST(vehicle_list, remove) {
	VehicleList manager;

	IVehicle *vehicle1 = new PassengerVehicle("1", "1", "1", 2001, 1);
	IVehicle *vehicle2 = new PassengerVehicle("2", "2", "2", 2002, 2);

	manager.add(vehicle1);

	ASSERT_FALSE(manager.remove(*vehicle2));

	manager.add(vehicle2);

	ASSERT_TRUE(manager.remove(*vehicle2));

	ASSERT_TRUE(manager.remove(*vehicle1));

	ASSERT_FALSE(manager.remove(*vehicle1));
}

TEST(vehicle_list, get) {
	VehicleList manager;

	IVehicle *vehicle1 = new PassengerVehicle("1", "1", "1", 2001, 1);

	manager.add(vehicle1);

	ASSERT_EQ(manager.get("1"), *vehicle1);
	EXPECT_THROW(manager.get("2"), NonExistentVehicleException);
}