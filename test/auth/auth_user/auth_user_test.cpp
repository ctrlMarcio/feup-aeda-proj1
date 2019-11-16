#include <gtest/gtest.h>
#include <auth/auth_user/auth_user.h>
#include <auth/auth_user/auth_user_manager.h>


using testing::Eq;


TEST(auth_user, misc) {
    AuthUserManager manager;
    AuthUser auth_user1 = manager.build("255716320", "1234565", AuthUser::ADMIN_ROLE);
    AuthUser auth_user2 = manager.build("255716320", "1234565", AuthUser::ADMIN_ROLE);
    AuthUser auth_user3 = manager.build("255716321", "1234565", AuthUser::ADMIN_ROLE);

    ASSERT_TRUE(auth_user1 == auth_user2);
    ASSERT_TRUE(auth_user1 != auth_user3);
    ASSERT_EQ(AuthUser::ADMIN_ROLE, auth_user1.getRole());
}