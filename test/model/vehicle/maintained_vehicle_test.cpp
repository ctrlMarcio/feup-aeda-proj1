#include <gtest/gtest.h>
#include <model/vehicle/maintained_vehicle.h>
#include <model/vehicle/passenger_vehicle.h>

using testing::Eq;

TEST(maintained_vehicle, set_maintenance_day) {
	PassengerVehicle pv("plate", "model", "brand", 2005, 5);
	Date date(20, 1, 2099); // distant date so it "never" fails
	Date wrong(27, 12, 2019);

	MaintainedVehicle vehicle(pv, date);
	EXPECT_FALSE(vehicle.setMaintenanceDay(wrong));
	EXPECT_TRUE(vehicle.setMaintenanceDay(date));
}