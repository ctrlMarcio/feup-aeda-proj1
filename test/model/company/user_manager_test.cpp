#include <gtest/gtest.h>
#include <model/company/company.h>

#include <utility>

using testing::Eq;

TEST(user_manager, all_tests) {
    Company company;

    class User : public IUser {
    private:
        string name, i_number, address, password;
    public:
        User(string name, string i_number, string address, string password) : name(std::move(name)), i_number(i_number),
                                                                            address(address), password(password) {}

        string getName() const override {
            return name;
        }

        string getIdentificationNumber() const override {
            return i_number;
        }

        string getAddress() const override {
            return address;
        }

        string getPassword() const override {
            return password;
        }
    };

    User *robert = new User("Robert", "255716320", "5th avenue, 23 SW", "rei_delas_69");

    ASSERT_FALSE(company.getUserManager().has("123"));
    ASSERT_FALSE(company.getUserManager().has(robert));

    company.getUserManager().add(robert);

    ASSERT_TRUE(company.getUserManager().has(robert));
    ASSERT_TRUE(company.getUserManager().has(robert->getIdentificationNumber()));

    ASSERT_EQ(robert, company.getUserManager().getUser(robert->getIdentificationNumber()));

    company.getUserManager().remove(robert);

    ASSERT_FALSE(company.getUserManager().has(robert));
    ASSERT_FALSE(company.getUserManager().has(robert->getIdentificationNumber()));
}