#include <gtest/gtest.h>
#include <model/schedule/schedule.h>
#include <exception/invalid_schedule_exception.h>

using testing::Eq;

TEST(schedule, is_inside) {
	Schedule schedule1(Date(23, 12, 2019), Date(24, 12, 2019));
	Schedule schedule2(Date(1, 12, 2019), Date(31, 12, 2019));
	Schedule schedule3(Date(25, 11, 2019), Date(24, 12, 2019));

	EXPECT_TRUE(schedule1.isInside(schedule2));
	EXPECT_FALSE(schedule2.isInside(schedule3));
	EXPECT_TRUE(schedule1.isInside(schedule3));
	EXPECT_TRUE(schedule3.isInside(schedule3));
}

TEST(schedule, interferes_with) {
	Schedule schedule1(Date(23, 12, 2019), Date(25, 12, 2019));
	Schedule schedule2(Date(11, 12, 2019), Date(12, 12, 2019));
	Schedule schedule3(Date(11, 12, 2019), Date(24, 12, 2019));
	Schedule schedule4(Date(23, 12, 2019), Date(24, 12, 2019));
	Schedule schedule5(Date(24, 12, 2019), Date(30, 12, 2019));
	Schedule schedule6(Date(26, 12, 2019), Date(27, 12, 2059));
	Schedule schedule7(Date(26, 12, 2012), Date(27, 12, 2059));

	EXPECT_TRUE(schedule1.interferesWith(schedule1));
	EXPECT_FALSE(schedule1.interferesWith(schedule2));
	EXPECT_TRUE(schedule1.interferesWith(schedule3));
	EXPECT_TRUE(schedule1.interferesWith(schedule4));
	EXPECT_TRUE(schedule1.interferesWith(schedule5));
	EXPECT_FALSE(schedule1.interferesWith(schedule6));
	EXPECT_TRUE(schedule1.interferesWith(schedule7));
}

TEST(schedule, merge_with) {
	Schedule schedule1(Date(23, 12, 2019), Date(25, 12, 2019));
	Schedule schedule2(Date(11, 12, 2019), Date(12, 12, 2019));
	Schedule schedule3(Date(11, 12, 2019), Date(24, 12, 2019));
	Schedule schedule4(Date(23, 12, 2019), Date(24, 12, 2019));
	Schedule schedule5(Date(24, 12, 2019), Date(30, 12, 2019));
	Schedule schedule6(Date(26, 12, 2019), Date(27, 12, 2059));
	Schedule schedule7(Date(26, 12, 2012), Date(27, 12, 2059));

	Schedule merge1(Date(11, 12, 2019), Date(25, 12, 2019));
	Schedule merge2(Date(23, 12, 2019), Date(30, 12, 2019));

	EXPECT_EQ(schedule1.mergeWith(schedule1), schedule1);
	EXPECT_EQ(schedule1.mergeWith(schedule2), schedule1);
	EXPECT_EQ(schedule1.mergeWith(schedule3), merge1);
	EXPECT_EQ(schedule1.mergeWith(schedule4), schedule1);
	EXPECT_EQ(schedule1.mergeWith(schedule5), merge2);
	EXPECT_EQ(schedule1.mergeWith(schedule6), schedule1);
	EXPECT_EQ(schedule1.mergeWith(schedule7), schedule7);
}

TEST(schedule, is_invalid) {
	ASSERT_NO_THROW(Schedule schedule1(Date(23, 12, 2019), Date(25, 12, 2019)));
	ASSERT_THROW(Schedule schedule2(Date(25, 12, 2019), Date(23, 12, 2019)), InvalidScheduleException);
	ASSERT_THROW(Schedule schedule3(Date(25, 12, 2019), Date(25, 12, 2019)), InvalidScheduleException);
}

TEST(schedule, equal_comparison_operator) {
	Schedule schedule1(Date(23, 12, 2019), Date(25, 12, 2019));
	Schedule schedule2(Date(23, 12, 2019), Date(25, 12, 2019));
	Schedule schedule3(Date(23, 12, 2019, 12, 12, 12), Date(25, 12, 2019));
	Schedule schedule4(Date(23, 12, 2019), Date(25, 12, 2019, 12, 12, 12));

	EXPECT_EQ(schedule1, schedule1);
	EXPECT_EQ(schedule1, schedule2);
	EXPECT_FALSE(schedule1 == schedule3);
	EXPECT_FALSE(schedule1 == schedule4);
}