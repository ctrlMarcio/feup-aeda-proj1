#include <gtest/gtest.h>
#include <model/offer/offer.h>
#include <model/vehicle/passenger_vehicle.h>

using testing::Eq;

TEST(offer, remove_schedule_availability) {
	// hasSchedule tested here as well

	PassengerVehicle vehicle("ab-ab-12", "Opel", "Corsa", 2012, 5);
	Schedule schedule1(Date(21, 12, 2019), Date(22, 12, 2019));
	Schedule schedule2(Date(4, 1, 2020), Date(5, 1, 2020));
	std::list<Schedule> schedules{schedule1, schedule2};
	Client provider("Client", "123", "Porto");

	Offer offer(vehicle, schedules, provider);

	ASSERT_TRUE(offer.hasSchedule(schedule1));
	offer.removeScheduleAvailability(schedule1);
	ASSERT_FALSE(offer.hasSchedule(schedule1));

	ASSERT_TRUE(offer.hasSchedule(schedule2));
	offer.removeScheduleAvailability(schedule2);
	ASSERT_FALSE(offer.hasSchedule(schedule2));

	ASSERT_NO_THROW(offer.removeScheduleAvailability(schedule1));

	ASSERT_TRUE(offer.getAvailableSchedules().empty());
}

TEST(offer, add_schedule) {
	PassengerVehicle vehicle("ab-ab-12", "Opel", "Corsa", 2012, 5);
	std::list<Schedule> schedules;
	Client provider("Client", "123", "Porto");

	Offer offer(vehicle, schedules, provider);

	offer.addSchedule(Date(21, 12, 2019), Date(22, 12, 2019));
	ASSERT_TRUE(offer.getAvailableSchedules().size() == 1);

	Schedule schedule(Date(4, 1, 2020), Date(5, 1, 2020));
	offer.addSchedule(schedule);
	ASSERT_TRUE(offer.getAvailableSchedules().size() == 2);

	offer.addSchedule(Date(3, 12, 2019), Date(25, 12, 2019));
	ASSERT_TRUE(offer.getAvailableSchedules().size() == 2);

	offer.addSchedule(Date(3, 1, 2020), Date(25, 1, 2020));
	ASSERT_TRUE(offer.getAvailableSchedules().size() == 2);

	EXPECT_FALSE(offer.addSchedule(Date(25, 1, 2020), Date(3, 1, 2020)));
}

TEST(offer, equal_comparison_operator) {
	PassengerVehicle vehicle("ab-ab-12", "Opel", "Corsa", 2012, 5);
	PassengerVehicle vehicle1("cd-cd-34", "Opel", "Astra", 2015, 5);
	Schedule schedule1(Date(21, 12, 2019), Date(22, 12, 2019));
	Schedule schedule2(Date(4, 1, 2020), Date(5, 1, 2020));
	std::list<Schedule> schedules{schedule1, schedule2};
	Client provider("Client", "123", "Porto");
	Client provider1("Client1", "456", "Porto");

	Offer offer1(vehicle, schedules, provider);
	Offer offer2(vehicle, schedules, provider);
	Offer offer3(vehicle, schedules, provider1);
	Offer offer4(vehicle1, schedules, provider);

	EXPECT_EQ(offer1, offer2);
	EXPECT_EQ(offer1, offer3);

	offer3.removeScheduleAvailability(schedule1);
	ASSERT_FALSE(offer1 == offer3);
	ASSERT_FALSE(offer1 == offer4);
}

TEST(offer, set_price) {
	PassengerVehicle vehicle("ab-ab-12", "Opel", "Corsa", 2012, 5);
	Schedule schedule1(Date(21, 12, 2019), Date(22, 12, 2019));
	Schedule schedule2(Date(4, 1, 2020), Date(5, 1, 2020));
	std::list<Schedule> schedules{schedule1, schedule2};
	Client provider("Client", "123", "Porto");

	Offer offer(vehicle, schedules, provider);

	float correct_price = 123.5;
	float wrong_price = -5;

	ASSERT_TRUE(offer.setPrice(correct_price));
	ASSERT_EQ(offer.getPrice(), correct_price);
	ASSERT_FALSE(offer.setPrice(wrong_price));
	ASSERT_EQ(offer.getPrice(), correct_price);
}