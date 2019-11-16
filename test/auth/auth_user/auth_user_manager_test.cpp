#include <gtest/gtest.h>
#include <auth/auth_user/auth_user.h>
#include <auth/auth_user/auth_user_manager.h>


using testing::Eq;


TEST(auth_user_manager, build) {
    AuthUserManager manager;
    AuthUser auth_user = manager.build("255716320", "1234565", AuthUser::ADMIN_ROLE);

    ASSERT_EQ(auth_user.getIdentificationNumber(), "255716320");
    ASSERT_EQ(auth_user.getPassword(), "1234565");
}

TEST(auth_user_manager, add) {
    AuthUserManager manager;
    AuthUser auth_user = manager.build("255716320", "1234565", AuthUser::ADMIN_ROLE);
    AuthUser auth_user_2 = manager.build("255716320", "1234565455", AuthUser::ADMIN_ROLE);

    ASSERT_TRUE(manager.add(auth_user));
    ASSERT_FALSE(manager.add(auth_user));
    ASSERT_FALSE(manager.add(auth_user_2));
    ASSERT_TRUE(manager.has(auth_user));
    ASSERT_TRUE(manager.has(auth_user.getIdentificationNumber()));
}

TEST(auth_user_manager, remove) {
    AuthUserManager manager;
    AuthUser auth_user = manager.build("255716320", "1234565", AuthUser::ADMIN_ROLE);
    AuthUser auth_user_2 = manager.build("255716321", "1234565455", AuthUser::ADMIN_ROLE);

    manager.add(auth_user);

    ASSERT_FALSE(manager.remove(auth_user_2));
    ASSERT_TRUE(manager.has(auth_user));
    ASSERT_TRUE(manager.remove(auth_user));
    ASSERT_FALSE(manager.has(auth_user));
}

TEST(auth_user_manager, get_user) {
    AuthUserManager manager;
    AuthUser auth_user = manager.build("255716320", "1234565", AuthUser::ADMIN_ROLE);

    manager.add(auth_user);

    ASSERT_TRUE(manager.has(auth_user));
    ASSERT_EQ(manager.getUser(auth_user.getIdentificationNumber()), auth_user);
}

TEST(auth_user_manager, misc) {
    AuthUserManager manager;
    AuthUser auth_user = manager.build("255716320", AuthUser::ADMIN_ROLE);

    manager.add(auth_user);
    ASSERT_TRUE(manager.has(auth_user));
    ASSERT_EQ(manager.getUser(auth_user.getIdentificationNumber()), auth_user);
}

