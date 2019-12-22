#include <gtest/gtest.h>
#include <model/company/user_manager.h>

using testing::Eq;

TEST(user_manager, get_provider) {
	UserManager user_manager;

	AdminManager &admin_manager = user_manager.getAdminManager();
	Admin admin("admin", "123", "Porto");
	admin_manager.add(admin);

	ClientManager &client_manager = user_manager.getClientManager();
	Client client("client", "456", "Lisboa");
	client_manager.add(client);

	EXPECT_EQ(user_manager.getProvider("123")->getIdentificationNumber(), admin.getIdentificationNumber());
	EXPECT_EQ(user_manager.getProvider("456")->getIdentificationNumber(), client.getIdentificationNumber());
	EXPECT_FALSE(user_manager.getProvider("123")->getIdentificationNumber() == client.getIdentificationNumber());
	EXPECT_FALSE(user_manager.getProvider("456")->getIdentificationNumber() == admin.getIdentificationNumber());
}

TEST(user_manager, get_renter) {
	UserManager user_manager;

	ClientCompanyManager &clientCompanyManager = user_manager.getClientCompanyManager();
	ClientCompany client_company("", "123", "Porto");
	clientCompanyManager.add(client_company);

	ClientManager &client_manager = user_manager.getClientManager();
	Client client("client", "456", "Lisboa");
	client_manager.add(client);

	EXPECT_EQ(user_manager.getRenter("123")->getIdentificationNumber(), client_company.getIdentificationNumber());
	EXPECT_EQ(user_manager.getRenter("456")->getIdentificationNumber(), client.getIdentificationNumber());
	EXPECT_FALSE(user_manager.getRenter("123")->getIdentificationNumber() == client.getIdentificationNumber());
	EXPECT_FALSE(user_manager.getRenter("456")->getIdentificationNumber() == client_company.getIdentificationNumber());
}