#include <gtest/gtest.h>
#include <model/offer/offer_manager.h>
#include <model/vehicle/passenger_vehicle.h>
#include <model/vehicle/commercial_vehicle.h>
#include <exception/non_existent_offer_exception.h>

using testing::Eq;

TEST(offer_manager, build) {
	PassengerVehicle vehicle("plate", "brand", "model", 2010, 5);
	Schedule schedule(Date(5, 5, 2010), Date());
	list<Schedule> schedules{schedule};
	Client client("name", "id", "address");

	Offer offer(vehicle, schedules, client);
	Offer built = *OfferManager::build(vehicle, schedules, client);

	EXPECT_EQ(offer, built);
}

TEST(offer_manager, get_recommended_offers) {
	OfferManager manager;

	PassengerVehicle vehicle1("plate1", "brand1", "model1", 2010, 5);
	CommercialVehicle vehicle2("plate2", "brand2", "model2", 2015, 10, 10, true);
	Schedule schedule(Date(5, 5, 2010), Date(30, 1, 3030));
	list<Schedule> schedules{schedule};
	Client client("name", "id", "address");

	Offer offer1(vehicle1, schedules, client);
	Offer offer2(vehicle2, schedules, client);

	manager.add(offer1);
	manager.add(offer2);

	PreferenceList preferences;

	EXPECT_TRUE(manager.getRecommendedOffers(preferences).empty());

	preferences.updatePreference(2010, 5);

	EXPECT_EQ(manager.getRecommendedOffers(preferences).size(), 1);

	preferences.updatePreference(2010, 10, 5, true);

	EXPECT_EQ(manager.getRecommendedOffers(preferences).size(), 2);

	preferences.updatePreference(2011, 5);

	EXPECT_EQ(manager.getRecommendedOffers(preferences).size(), 1);

	preferences.updatePreference(2010, 5, 11, true);

	EXPECT_TRUE(manager.getRecommendedOffers(preferences).empty());
}

TEST(offer_manager, has_offer_of) {
	OfferManager manager;

	PassengerVehicle vehicle1("plate1", "brand1", "model1", 2010, 5);
	CommercialVehicle vehicle2("plate2", "brand2", "model2", 2015, 10, 10, true);
	Schedule schedule(Date(5, 5, 2010), Date());
	list<Schedule> schedules{schedule};
	Client client("name", "id", "address");

	Offer offer1(vehicle1, schedules, client);
	Offer offer2(vehicle2, schedules, client);

	EXPECT_FALSE(manager.hasOfferOf(vehicle1));
	EXPECT_FALSE(manager.hasOfferOf(vehicle2));

	manager.add(offer1);

	EXPECT_TRUE(manager.hasOfferOf(vehicle1));
	EXPECT_FALSE(manager.hasOfferOf(vehicle2));

	manager.add(offer2);

	EXPECT_TRUE(manager.hasOfferOf(vehicle1));
	EXPECT_TRUE(manager.hasOfferOf(vehicle2));

	manager.remove(offer2);

	EXPECT_FALSE(manager.hasOfferOf(vehicle2));
}

TEST(offer_manager, get_offer_of) {
	OfferManager manager;

	PassengerVehicle vehicle1("plate1", "brand1", "model1", 2010, 5);
	CommercialVehicle vehicle2("plate2", "brand2", "model2", 2015, 10, 10, true);
	Schedule schedule(Date(5, 5, 2010), Date());
	list<Schedule> schedules{schedule};
	Client client("name", "id", "address");

	Offer offer1(vehicle1, schedules, client);
	Offer offer2(vehicle2, schedules, client);

	EXPECT_THROW(manager.getOfferOf(vehicle1), NonExistentOfferException);

	ASSERT_TRUE(manager.add(offer1));

	EXPECT_EQ(manager.getOfferOf(vehicle1), offer1);

	EXPECT_THROW(manager.getOfferOf(vehicle2), NonExistentOfferException);

	ASSERT_TRUE(manager.add(offer2));

	EXPECT_EQ(manager.getOfferOf(vehicle2), offer2);

	manager.remove(offer2);

	EXPECT_THROW(manager.getOfferOf(vehicle2), NonExistentOfferException);
}

TEST(offer_manager, add) {
	OfferManager manager;

	PassengerVehicle vehicle1("plate1", "brand1", "model1", 2010, 5);
	CommercialVehicle vehicle2("plate2", "brand2", "model2", 2015, 10, 10, true);
	Schedule schedule(Date(5, 5, 2010), Date());
	list<Schedule> schedules{schedule};
	Client client("name", "id", "address");

	Offer offer1(vehicle1, schedules, client);
	Offer offer2(vehicle2, schedules, client);

	EXPECT_TRUE(manager.add(offer1));
	ASSERT_TRUE(manager.hasOfferOf(vehicle1));
	EXPECT_TRUE(manager.add(offer2));
	EXPECT_TRUE(manager.hasOfferOf(vehicle2));
	EXPECT_FALSE(manager.add(offer1));
	EXPECT_FALSE(manager.add(offer2));
}

TEST(offer_manager, remove_day) {
	OfferManager manager;

	PassengerVehicle vehicle1("plate1", "brand1", "model1", 2010, 5);
	PassengerVehicle vehicle2("plate2", "brand2", "model2", 2011, 5);
	PassengerVehicle vehicle3("plat3", "brand3", "model3", 2012, 5);
	Schedule schedule1(Date(5, 2, 2020, 12), Date(7, 2, 2020, 12));
	list<Schedule> schedules{schedule1};
	Client client("name", "id", "address");

	Offer offer1(vehicle1, schedules, client);
	Offer offer2(vehicle2, schedules, client);
	Offer offer3(vehicle3, schedules, client);

	manager.add(offer1);
	manager.add(offer2);
	manager.add(offer3);

	manager.removeDay(vehicle1, Date(5, 2, 2020));
	EXPECT_EQ(manager.getOffers()[0]->getAvailableSchedules().begin()->getBegin(), Date(6, 2, 2020));
	manager.removeDay(vehicle2, Date(6, 2, 2020));
	ASSERT_EQ(manager.getOffers()[1]->getAvailableSchedules().size(), 2);
	EXPECT_EQ(manager.getOffers()[1]->getAvailableSchedules().begin()->getEnd(), Date(5, 2, 2020, 23, 59, 59));
	EXPECT_EQ((manager.getOffers()[1]->getAvailableSchedules().back()).getBegin(), Date(7, 2, 2020));
	manager.removeDay(vehicle3, Date(7, 2, 2020));
	EXPECT_EQ(manager.getOffers()[2]->getAvailableSchedules().begin()->getEnd(), Date(6, 2, 2020, 23, 59, 59));
}

TEST(offer_manager, remove) {
	OfferManager manager;

	PassengerVehicle vehicle1("plate1", "brand1", "model1", 2010, 5);
	CommercialVehicle vehicle2("plate2", "brand2", "model2", 2015, 10, 10, true);
	Schedule schedule(Date(5, 5, 2010), Date());
	list<Schedule> schedules{schedule};
	Client client("name", "id", "address");

	Offer offer1(vehicle1, schedules, client);
	Offer offer2(vehicle2, schedules, client);

	manager.add(offer1);
	manager.add(offer2);

	EXPECT_TRUE(manager.remove(offer1));
	EXPECT_FALSE(manager.hasOfferOf(vehicle1));
	EXPECT_EQ(manager.getOffers().size(), 1);
	EXPECT_FALSE(manager.remove(offer1));
	EXPECT_TRUE(manager.remove(offer2));
	EXPECT_FALSE(manager.hasOfferOf(vehicle2));
	EXPECT_EQ(manager.getOffers().size(), 0);
	EXPECT_FALSE(manager.remove(offer2));
}

TEST(offer_manager, get_possible_offers) {
	OfferManager manager;

	PassengerVehicle vehicle1("plate1", "brand1", "model1", 2010, 5);
	CommercialVehicle vehicle2("plate2", "brand2", "model2", 2015, 10, 10, true);
	Schedule schedule(Date(5, 5, 2010), Date());
	list<Schedule> schedules{schedule};
	Client client("name", "id", "address");

	Offer offer1(vehicle1, schedules, client);

	schedules.emplace_back(Date(1, 1, 1), Date(20, 2, 3000));
	Offer offer2(vehicle2, schedules, client);

	manager.add(offer1);
	manager.add(offer2);

	ASSERT_TRUE(manager.hasOfferOf(vehicle1));
	ASSERT_TRUE(manager.hasOfferOf(vehicle2));

	Date now;
	ASSERT_EQ(manager.getPossibleOffers().size(), 1);
	ASSERT_GE(manager.getPossibleOffers()[0].getAvailableSchedules().front().getBegin(), now);
}
