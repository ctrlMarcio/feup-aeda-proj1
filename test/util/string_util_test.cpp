#include <gtest/gtest.h>
#include <util/string_util.h>
#include <util/bst.h>
#include <model/contract/contract.h>
#include <model/user/i_provider.h>
#include <model/user/client.h>


using namespace std;
using namespace string_util;
using testing::Eq;

TEST(string_util, split) {
	std::vector<string> vector{"Hi", "my", "name", "is", "Abel"};
	std::vector<string> abcd{"abcd"};

	EXPECT_EQ(split("Hi my name is Abel", " "), vector);
	EXPECT_EQ(split("abcd", "1"), abcd);
}

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

    string padded = pad_number(number, 5);

    ASSERT_EQ("00323", padded);
}