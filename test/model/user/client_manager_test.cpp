#include <gtest/gtest.h>
#include <model/user/client.h>
#include <model/user/client_manager.h>

using testing::Eq;

TEST(client_manager, build) {
	string name = "name";
	string id = "id";
	string address = "address";

	Client client(name, id, address);

	ASSERT_EQ(ClientManager::build(name, id, address), client);
}

TEST(client_manager, add) {
	ClientManager manager;

	Client client1("1", "1", "1");
	Client client2("2", "2", "2");

	ASSERT_TRUE(manager.add(client1));

	EXPECT_TRUE(manager.has(client1));
	EXPECT_FALSE(manager.has(client2));

	ASSERT_FALSE(manager.add(client1));
	ASSERT_TRUE(manager.add(client2));

	EXPECT_TRUE(manager.has(client2));

	ASSERT_FALSE(manager.add(client2));
}

TEST(client_manager, remove) {
	ClientManager manager;

	Client admin1("1", "1", "1");
	Client admin2("2", "2", "2");

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

TEST(client_manager, get) {
	ClientManager manager;

	Client admin1("1", "1", "1");

	manager.add(admin1);

	ASSERT_EQ(*manager.get("1"), admin1);
	ASSERT_EQ(manager.get("2"), nullptr);
}