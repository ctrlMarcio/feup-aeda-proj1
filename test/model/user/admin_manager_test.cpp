#include <gtest/gtest.h>
#include <model/user/admin.h>
#include <model/user/admin_manager.h>

using testing::Eq;

TEST(admin_manager, build) {
	string name = "name";
	string id = "id";
	string address = "address";

	Admin admin(name, id, address);

	ASSERT_EQ(AdminManager::build(name, id, address), admin);
}

TEST(admin_manager, set_vehicle_list) {
	AdminManager manager;
	VehicleList *vehicle_list = new VehicleList();

	Admin admin1("1", "1", "1");
	Admin admin2("2", "2", "2");

	manager.add(admin1);
	manager.add(admin2);

	EXPECT_EQ(&admin1.getVehicleList(), nullptr);

	manager.setVehicleList(vehicle_list);

	EXPECT_EQ(&manager.get("1")->getVehicleList(), vehicle_list);
	EXPECT_EQ(&manager.get("2")->getVehicleList(), vehicle_list);
}

TEST(admin_manager, add) {
	AdminManager manager;

	Admin admin1("1", "1", "1");
	Admin admin2("2", "2", "2");

	ASSERT_TRUE(manager.add(admin1));

	EXPECT_TRUE(manager.has(admin1));
	EXPECT_FALSE(manager.has(admin2));

	ASSERT_FALSE(manager.add(admin1));
	ASSERT_TRUE(manager.add(admin2));

	EXPECT_TRUE(manager.has(admin2));

	ASSERT_FALSE(manager.add(admin2));
}

TEST(admin_manager, remove) {
	AdminManager manager;

	Admin admin1("1", "1", "1");
	Admin admin2("2", "2", "2");

	manager.add(admin1);

	ASSERT_FALSE(manager.remove(admin2));

	manager.add(admin2);

	ASSERT_TRUE(manager.has(admin1));
	ASSERT_TRUE(manager.has(admin2));

	ASSERT_TRUE(manager.remove(admin2));

	ASSERT_TRUE(manager.has(admin1));
	ASSERT_FALSE(manager.has(admin2));

	ASSERT_TRUE(manager.remove(admin1));

	ASSERT_FALSE(manager.has(admin1));
	ASSERT_FALSE(manager.has(admin2));

	ASSERT_FALSE(manager.remove(admin1));
}

TEST(admin_manager, get) {
	AdminManager manager;

	Admin admin1("1", "1", "1");

	manager.add(admin1);

	ASSERT_EQ(*manager.get("1"), admin1);
	ASSERT_EQ(manager.get("2"), nullptr);
}