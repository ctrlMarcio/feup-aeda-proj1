#include <gtest/gtest.h>
#include <model/rental/rental_manager.h>
#include <model/vehicle/passenger_vehicle.h>

using testing::Eq;

TEST(rental_manager, build) {
	PassengerVehicle vehicle("a", "b", "c", 2015, 5);
	Date begin(1, 1, 1);
	Date end(2, 2, 2);
	Date diff(3, 3, 3);
	Schedule schedule(begin, end);
	std::list<Schedule> list{schedule};
	Client client("name", "id", "address");
	float price = 10;
	Offer offer(vehicle, list, client, price);

	Rental rental(offer, schedule, client);

	EXPECT_EQ(RentalManager::build(offer, schedule, client), rental);
	EXPECT_EQ(RentalManager::build(offer, begin, end, client), rental);
	EXPECT_FALSE(RentalManager::build(offer, begin, diff, client) == rental);
}

TEST(rental_manager, add) {
	RentalManager manager;

	PassengerVehicle vehicle("a", "b", "c", 2015, 5);
	Date begin(1, 1, 1);
	Date end(2, 2, 2);
	Date diff(3, 3, 3);
	Schedule schedule(begin, end);
	Schedule schedule1(begin, diff);
	std::list<Schedule> list{schedule};
	Client client("name", "id", "address");
	float price = 10;
	Offer offer(vehicle, list, client, price);

	Rental rental(offer, schedule, client);
	Rental rental1(offer, schedule1, client);

	EXPECT_TRUE(manager.add(rental));
	EXPECT_FALSE(manager.add(rental1));
	EXPECT_FALSE(manager.add(rental));
}