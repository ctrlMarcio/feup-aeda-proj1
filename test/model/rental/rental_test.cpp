#include <gtest/gtest.h>
#include <model/offer/offer.h>
#include <model/schedule/schedule.h>
#include <model/rental/rental.h>

using testing::Eq;

TEST(rental, constructor) {
	Offer offer{};
	Schedule schedule(Date(1, 1, 2019), Date(2, 1, 2019));

	Rental rental(offer, schedule);

	// Verifies that the rental object only holds a reference
	EXPECT_EQ(&(rental.getOffer()), &(offer));
}