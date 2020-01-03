#include <gtest/gtest.h>
#include <model/user/client.h>
#include <model/user/client_manager.h>
#include <model/offer/offer_manager.h>
#include <model/rental/rental_manager.h>
#include <model/contract/contract_manager.h>
#include <model/vehicle/passenger_vehicle.h>

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

TEST(client_manager, get_inactive_clients) {
    ClientManager manager;
    OfferManager om;
    RentalManager rm;
    ContractManager cm(rm, om);

    Client *client = new Client("1", "1", "1");
    IProvider *user = client;

    Date contract_date;
    for (long i = 0; i < ClientManager::DAYS_TO_INACTIVITY; i++)
        contract_date = contract_date.removeDay();

    PassengerVehicle vehicle("ab-ab-12", "Opel", "Corsa", 2012, 5);
    std::list<Schedule> schedules;
    Client provider("Client", "123", "Porto");

    Offer offer(vehicle, schedules, provider);
    Contract *contract = new TransferContract(contract_date, user, ContractType::TRANSFER, offer);
    cm.add(contract);

    manager.add(*client);

    manager.update(cm);

    ASSERT_EQ(manager.getInactiveClients().size(), 1);
    EXPECT_EQ(*manager.getInactiveClients()[0], *client);
}

TEST(client_manager, update) {
    ClientManager manager;
    OfferManager om;
    RentalManager rm;
    ContractManager cm(rm, om);

    Client *client1 = new Client("1", "1", "1");
    IProvider *user1 = client1;

    Client *client2 = new Client("2", "2", "2");
    IProvider *user2 = client2;

    Date contract_date1(1, 1, 2000);
    Date contract_date2;
    contract_date2 = contract_date2.removeDay();

    PassengerVehicle vehicle("ab-ab-12", "Opel", "Corsa", 2012, 5);
    std::list<Schedule> schedules;
    Client provider("Client", "123", "Porto");

    Offer offer(vehicle, schedules, provider);

    Contract *contract1 = new TransferContract(contract_date1, user1, ContractType::TRANSFER, offer);
    cm.add(contract1);

    Contract *contract2 = new TransferContract(contract_date1, user2, ContractType::TRANSFER, offer);
    cm.add(contract2);

    manager.add(*client1);
    manager.add(*client2);

    manager.update(cm);

    EXPECT_EQ(manager.getInactiveClients().size(), 2);

    Contract *contract3 = new TransferContract(contract_date2, user2, ContractType::TRANSFER, offer);
    cm.add(contract3);

    manager.update(cm);

    EXPECT_EQ(manager.getInactiveClients().size(), 1);
}