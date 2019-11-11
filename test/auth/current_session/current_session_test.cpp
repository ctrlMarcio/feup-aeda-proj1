#include <gtest/gtest.h>
#include <auth/auth_user/auth_user_manager.h>
#include <auth/current_session/current_session.h>
#include <exception/invalid_login_exception.h>


using testing::Eq;


TEST(current_session, login) {
    AuthUserManager manager;
    AuthUser user = manager.build("255716320", "12345678");

    CurrentSession session(manager);

    manager.add(user);

    ASSERT_THROW(session.login("1234124", "312313"), InvalidLoginException);
    ASSERT_THROW(session.login("255716320", "312313"), InvalidLoginException);

    ASSERT_EQ(session.getUser(), AuthUser("", ""));

    ASSERT_NO_THROW(session.login("255716320", "12345678"));

    ASSERT_EQ(session.getUser(), user);

    ASSERT_EQ(session.getUser().getIdentificationNumber(), user.getIdentificationNumber());
}

TEST(current_session, logout) {
    AuthUserManager manager;
    AuthUser user = manager.build("255716320", "12345678");

    CurrentSession session(manager);

    manager.add(user);

    ASSERT_NO_THROW(session.login("255716320", "12345678"));

    ASSERT_EQ(session.getUser(), user);

    session.logout();

    ASSERT_EQ(session.getUser(), AuthUser("", ""));
}