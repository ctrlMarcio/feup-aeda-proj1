#include <gtest/gtest.h>
#include <model/company/company.h>

using testing::Eq;

TEST(a, b){
	Company company;
	ASSERT_TRUE(company.get());
}