#include <gtest/gtest.h>
#include <exception/invalid_date_exception.h>

using testing::Eq;

TEST(date, constructor) {
    int v_day = 10, v_month = 10, v_year = 2019, v_hour = 10, v_minute = 20, v_second = 10;

    EXPECT_NO_THROW(Date(v_day, v_month, v_year, v_hour, v_minute, v_second));
    EXPECT_THROW(Date(0, v_month, v_year, v_hour, v_minute, v_second), InvalidDateException);
    EXPECT_THROW(Date(32, v_month, v_year, v_hour, v_minute, v_second), InvalidDateException);
    EXPECT_THROW(Date(30, 2, 2020, v_hour, v_minute, v_second), InvalidDateException);
    EXPECT_THROW(Date(29, 2, 2021, v_hour, v_minute, v_second), InvalidDateException);
    EXPECT_NO_THROW(Date(29, 2, 2020, v_hour, v_minute, v_second));
    EXPECT_NO_THROW(Date(28, 2, 2021, v_hour, v_minute, v_second));
    EXPECT_THROW(Date(31, 4, v_year, v_hour, v_minute, v_second), InvalidDateException);
    EXPECT_THROW(Date(v_day, 0, v_year, v_hour, v_minute, v_second), InvalidDateException);
    EXPECT_NO_THROW(Date(v_day, 1, v_year, v_hour, v_minute, v_second));
    EXPECT_THROW(Date(v_day, 13, v_year, v_hour, v_minute, v_second), InvalidDateException);
    EXPECT_NO_THROW(Date(v_day, 12, v_year, v_hour, v_minute, v_second));
    EXPECT_THROW(Date(v_day, v_month, v_year, -1, v_minute, v_second), InvalidDateException);
    EXPECT_NO_THROW(Date(v_day, v_month, v_year, 0, v_minute, v_second));
    EXPECT_THROW(Date(v_day, v_month, v_year, 24, v_minute, v_second), InvalidDateException);
    EXPECT_NO_THROW(Date(v_day, v_month, v_year, 23, v_minute, v_second));
    EXPECT_THROW(Date(v_day, v_month, v_year, v_hour, -1, v_second), InvalidDateException);
    EXPECT_NO_THROW(Date(v_day, v_month, v_year, v_hour, 0, v_second));
    EXPECT_THROW(Date(v_day, v_month, v_year, v_hour, 60, v_second), InvalidDateException);
    EXPECT_NO_THROW(Date(v_day, v_month, v_year, v_hour, 59, v_second));
    EXPECT_THROW(Date(v_day, v_month, v_year, v_hour, v_minute, -1), InvalidDateException);
    EXPECT_NO_THROW(Date(v_day, v_month, v_year, v_hour, v_minute, 0));
    EXPECT_THROW(Date(v_day, v_month, v_year, v_hour, v_minute, 60), InvalidDateException);
    EXPECT_NO_THROW(Date(v_day, v_month, v_year, v_hour, v_minute, 59));
    EXPECT_NO_THROW(Date(1, 1, 2000, 0, 0, 0));
    EXPECT_NO_THROW(Date(31, 12, 2099, 23, 59, 59));
}

TEST(date, current_date_constructor) {
    EXPECT_NO_THROW(Date());
}

TEST(date, greater_date) {
    Date date1(20, 12, 2018, 12, 20, 19);
    Date date2(20, 12, 2018, 12, 20, 18);
    Date date3(20, 12, 2018, 12, 19, 19);
    Date date4(20, 12, 2018, 11, 20, 19);
    Date date5(19, 12, 2018, 12, 20, 19);
    Date date6(20, 11, 2018, 12, 20, 19);
    Date date7(20, 12, 2017, 12, 20, 19);
    Date date8(20, 12, 2018, 12, 20, 19);

    ASSERT_TRUE(date1 > date2);
    ASSERT_TRUE(date1 > date3);
    ASSERT_TRUE(date1 > date4);
    ASSERT_TRUE(date1 > date5);
    ASSERT_TRUE(date1 > date6);
    ASSERT_TRUE(date1 > date7);

    ASSERT_FALSE(date2 > date1);
    ASSERT_FALSE(date3 > date1);
    ASSERT_FALSE(date4 > date1);
    ASSERT_FALSE(date5 > date1);
    ASSERT_FALSE(date6 > date1);
    ASSERT_FALSE(date7 > date1);
    ASSERT_FALSE(date8 > date1);
}

TEST(date, greater_or_equal_date) {
    Date date1(20, 12, 2018, 12, 20, 19);
    Date date2(20, 12, 2018, 12, 20, 18);
    Date date3(20, 12, 2018, 12, 19, 19);
    Date date4(20, 12, 2018, 11, 20, 19);
    Date date5(19, 12, 2018, 12, 20, 19);
    Date date6(20, 11, 2018, 12, 20, 19);
    Date date7(20, 12, 2017, 12, 20, 19);
    Date date8(20, 12, 2018, 12, 20, 19);

    ASSERT_TRUE(date1 >= date2);
    ASSERT_TRUE(date1 >= date3);
    ASSERT_TRUE(date1 >= date4);
    ASSERT_TRUE(date1 >= date5);
    ASSERT_TRUE(date1 >= date6);
    ASSERT_TRUE(date1 >= date7);

    ASSERT_FALSE(date2 >= date1);
    ASSERT_FALSE(date3 >= date1);
    ASSERT_FALSE(date4 >= date1);
    ASSERT_FALSE(date5 >= date1);
    ASSERT_FALSE(date6 >= date1);
    ASSERT_FALSE(date7 >= date1);

    ASSERT_TRUE(date1 >= date8);
    ASSERT_TRUE(date8 >= date1);
}

TEST(date, less_date) {
    Date date1(20, 12, 2018, 12, 20, 19);
    Date date2(20, 12, 2018, 12, 20, 18);
    Date date3(20, 12, 2018, 12, 19, 19);
    Date date4(20, 12, 2018, 11, 20, 19);
    Date date5(19, 12, 2018, 12, 20, 19);
    Date date6(20, 11, 2018, 12, 20, 19);
    Date date7(20, 12, 2017, 12, 20, 19);
    Date date8(20, 12, 2018, 12, 20, 19);

    ASSERT_FALSE(date1 < date2);
    ASSERT_FALSE(date1 < date3);
    ASSERT_FALSE(date1 < date4);
    ASSERT_FALSE(date1 < date5);
    ASSERT_FALSE(date1 < date6);
    ASSERT_FALSE(date1 < date7);

    ASSERT_TRUE(date2 < date1);
    ASSERT_TRUE(date3 < date1);
    ASSERT_TRUE(date4 < date1);
    ASSERT_TRUE(date5 < date1);
    ASSERT_TRUE(date6 < date1);
    ASSERT_TRUE(date7 < date1);

    ASSERT_FALSE(date8 < date1);
}

TEST(date, less_or_equal_date) {
    Date date1(20, 12, 2018, 12, 20, 19);
    Date date2(20, 12, 2018, 12, 20, 18);
    Date date3(20, 12, 2018, 12, 19, 19);
    Date date4(20, 12, 2018, 11, 20, 19);
    Date date5(19, 12, 2018, 12, 20, 19);
    Date date6(20, 11, 2018, 12, 20, 19);
    Date date7(20, 12, 2017, 12, 20, 19);
    Date date8(20, 12, 2018, 12, 20, 19);

    ASSERT_FALSE(date1 <= date2);
    ASSERT_FALSE(date1 <= date3);
    ASSERT_FALSE(date1 <= date4);
    ASSERT_FALSE(date1 <= date5);
    ASSERT_FALSE(date1 <= date6);
    ASSERT_FALSE(date1 <= date7);

    ASSERT_TRUE(date2 <= date1);
    ASSERT_TRUE(date3 <= date1);
    ASSERT_TRUE(date4 <= date1);
    ASSERT_TRUE(date5 <= date1);
    ASSERT_TRUE(date6 <= date1);
    ASSERT_TRUE(date7 <= date1);

    ASSERT_TRUE(date1 >= date8);
    ASSERT_TRUE(date8 >= date1);
}

TEST(date, misc) {
    Date date1(20, 12, 2018, 12, 20, 19);
    Date date2(20, 12, 2018, 12, 20, 19);
    Date date3(20, 12, 2018, 12, 20, 20);

    ASSERT_TRUE(date1 == date2);
    ASSERT_FALSE(date1 == date3);

    ASSERT_EQ("December", date1.getMonthName());
}