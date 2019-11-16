#include <gtest/gtest.h>
#include <util/string_util.h>


using namespace std;
using namespace string_util;
using testing::Eq;


TEST(string_util, trim) {
    string untrimmed = "     abc       ";
    string trimmed = trim(untrimmed);

    ASSERT_EQ("abc", trimmed);
}

TEST(string_util, is_number) {
    string number = "1234";
    string mixed = "1234a321";

    ASSERT_TRUE(is_number(number));
    ASSERT_FALSE(is_number(mixed));
}

TEST(string_util, pad_number) {
    int number = 323;

    string padded = pad_number(323, 5);

    ASSERT_EQ("00323", padded);
}