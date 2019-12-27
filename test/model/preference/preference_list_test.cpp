#include <gtest/gtest.h>
#include <model/preference/preference_list.h>

using testing::Eq;

TEST(preference_list, update_preference) {
	PreferenceList preference_list;

	EXPECT_EQ(preference_list.getPassengerPreference(), nullptr);
	EXPECT_EQ(preference_list.getCommercialPreference(), nullptr);

	ASSERT_TRUE(preference_list.updatePreference(2012, 5));

	EXPECT_EQ(preference_list.getPassengerPreference()->getMinYear(), 2012);
	EXPECT_EQ(preference_list.getCommercialPreference(), nullptr);

	ASSERT_TRUE(preference_list.updatePreference(2013, 4, 4, true));

	EXPECT_EQ(preference_list.getPassengerPreference()->getMinYear(), 2012);
	EXPECT_EQ(preference_list.getCommercialPreference()->getMinYear(), 2013);

	ASSERT_TRUE(preference_list.updatePreference(2019, 5));

	EXPECT_EQ(preference_list.getPassengerPreference()->getMinYear(), 2019);

	ASSERT_FALSE(preference_list.updatePreference(2099, 5));
	ASSERT_FALSE(preference_list.updatePreference(2099, 4, 4, true));
}

TEST(preference_list, equal_comparison_operator) {
	PreferenceList preference_list1;
	PreferenceList preference_list2;

	preference_list1.updatePreference(2012, 5);
	preference_list1.updatePreference(2013, 5, 5, true);
	preference_list2.updatePreference(2012, 5);
	preference_list2.updatePreference(2013, 5, 5, true);

	EXPECT_EQ(preference_list1, preference_list2);

	preference_list2.updatePreference(2014, 5, 5, true);

	EXPECT_TRUE(preference_list1 != preference_list2);

	preference_list2.updatePreference(2013, 5, 5, true);
	preference_list2.updatePreference(2014, 5);

	EXPECT_TRUE(preference_list1 != preference_list2);

	preference_list2.updatePreference(2012, 5);

	EXPECT_FALSE(preference_list1 != preference_list2);
}

TEST(preference_list, remove_preference) {
	PreferenceList preference_list1;
	preference_list1.updatePreference(2012, 5);
	preference_list1.updatePreference(2013, 5, 5, true);

	EXPECT_FALSE(preference_list1.getPassengerPreference() == nullptr);
	EXPECT_FALSE(preference_list1.getCommercialPreference() == nullptr);

	preference_list1.removePassengerPreference();
	EXPECT_TRUE(preference_list1.getPassengerPreference() == nullptr);

	preference_list1.removeCommercialPreference();
	EXPECT_TRUE(preference_list1.getCommercialPreference() == nullptr);
}