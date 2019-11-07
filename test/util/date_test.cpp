#include <gtest/gtest.h>
#include <exception/invalid_date_exception.h>

using testing::Eq;

/* TODO
TEST(date, constructor) {
	int v_day = 10, v_month = 10, v_year = 2019, v_hour = 10, v_minute = 20, v_second = 10;

	ASSERT_THROW(Date(0, v_month, v_year, v_hour, v_minute, v_second), InvalidDateException);
	EXPECT_THROW(Date(32, v_month, v_year, v_hour, v_minute, v_second), InvalidDateException);
	EXPECT_THROW(Date(30, 2, 2020, v_hour, v_minute, v_second), InvalidDateException);
	EXPECT_THROW(Date(29, 2, 2021, v_hour, v_minute, v_second), InvalidDateException);
	EXPECT_THROW(Date(31, 4, v_year, v_hour, v_minute, v_second), InvalidDateException);
	EXPECT_THROW(Date(v_day, 0, v_year, v_hour, v_minute, v_second), InvalidDateException);
	EXPECT_THROW(Date(v_day, 13, v_year, v_hour, v_minute, v_second), InvalidDateException);
	EXPECT_THROW(Date(v_day, v_month, v_year, -1, v_minute, v_second), InvalidDateException);
	EXPECT_THROW(Date(v_day, v_month, v_year, 24, v_minute, v_second), InvalidDateException);
	EXPECT_THROW(Date(v_day, v_month, v_year, v_hour, -1, v_second), InvalidDateException);
	EXPECT_THROW(Date(v_day, v_month, v_year, v_hour, 60, v_second), InvalidDateException);
	EXPECT_THROW(Date(v_day, v_month, v_year, v_hour, v_minute, -1), InvalidDateException);
	EXPECT_THROW(Date(v_day, v_month, v_year, v_hour, v_minute, 60), InvalidDateException);
}
 */