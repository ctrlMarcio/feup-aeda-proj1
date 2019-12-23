#include <gtest/gtest.h>
#include <model/user/client_company.h>
#include <model/user/client_company_manager.h>

using testing::Eq;

TEST(client_company_manager, build) {
	string name = "name";
	string id = "id";
	string address = "address";

	ClientCompany client(name, id, address);

	ASSERT_EQ(ClientCompanyManager::build(name, id, address), client);
}

TEST(client_company_manager, add) {
	ClientCompanyManager manager;

	ClientCompany client1("1", "1", "1");
	ClientCompany client2("2", "2", "2");

	ASSERT_TRUE(manager.add(client1));

	EXPECT_TRUE(manager.has(client1));
	EXPECT_FALSE(manager.has(client2));

	ASSERT_FALSE(manager.add(client1));
	ASSERT_TRUE(manager.add(client2));

	EXPECT_TRUE(manager.has(client2));

	ASSERT_FALSE(manager.add(client2));
}

TEST(client_company_manager, remove) {
	ClientCompanyManager manager;

	ClientCompany admin1("1", "1", "1");
	ClientCompany admin2("2", "2", "2");

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

TEST(client_company_manager, get) {
	ClientCompanyManager manager;

	ClientCompany admin1("1", "1", "1");

	manager.add(admin1);

	ASSERT_EQ(*manager.get("1"), admin1);
	ASSERT_EQ(manager.get("2"), nullptr);
}