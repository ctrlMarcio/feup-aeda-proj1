#include <gtest/gtest.h>
#include <model/contract/contract_manager.h>

using testing::Eq;

TEST(contract_manager, days_since_last_contract) {
	RentalManager rm;
	OfferManager om;
	ContractManager manager(rm, om);

	Date date1(1, 1, 2010);
	Date date2(1, 1, 2011);
	Date date3(1, 1, 2009);

	IProvider *user1 = new Client("1", "1", "1");

	Contract *contract1 = new Contract(date1, user1, ContractType::TRANSFER);
	Contract *contract2 = new Contract(date2, user1, ContractType::TRANSFER);
	Contract *contract3 = new Contract(date3, user1, ContractType::TRANSFER);

	manager.add(contract1);

	unsigned long difference = date1.dayDifference(Date());

	EXPECT_EQ(manager.daysSinceLastContract("1"), difference);

	difference = date2.dayDifference(Date());
	manager.add(contract2);
	manager.add(contract3);

	EXPECT_EQ(manager.daysSinceLastContract("1"), difference);
	EXPECT_EQ(manager.daysSinceLastContract("asdjasd"), -1);
}

TEST(contract_manager, get_contracts_of) {
	RentalManager rm;
	OfferManager om;
	ContractManager manager(rm, om);

	Date date1(1, 1, 2010);
	Date date2(1, 1, 2011);
	Date date3(1, 1, 2019);
	Date date4(1, 1, 2000);

	IProvider *user1 = new Client("1", "1", "1");

	Contract *contract1 = new Contract(date1, user1, ContractType::TRANSFER);
	Contract *contract2 = new Contract(date2, user1, ContractType::TRANSFER);
	Contract *contract3 = new Contract(date3, user1, ContractType::TRANSFER);
	Contract *contract4 = new Contract(date4, user1, ContractType::TRANSFER);

	manager.add(contract1);
	manager.add(contract2);
	manager.add(contract3);
	manager.add(contract4);

	EXPECT_TRUE(manager.getContractsOf("aksjdh").empty());

	list<Contract> contracts = manager.getContractsOf("1");

	ASSERT_EQ(contracts.size(), 4);

	auto it = contracts.begin();
	EXPECT_EQ(*it, *contract4);
	++it;
	EXPECT_EQ(*it, *contract1);
	++it;
	EXPECT_EQ(*it, *contract2);
	++it;
	EXPECT_EQ(*it, *contract3);
}
