#include <gtest/gtest.h>
#include "userService.h"

TEST(UserServiceTest, registerUser)
{
    UserService userService;
    ASSERT_TRUE(userService.registerUser("username", "password", "fullName", "role", "department", "email"));
    ASSERT_TRUE(userService.registerUser("username2", "password2", "fullName2", "role2", "department2", "email2"));
    ASSERT_TRUE(userService.registerUser("username3", "password3", "fullName", "role", "department", "email"));
    ASSERT_FALSE(userService.registerUser("username", "password", "fullName", "role", "department", "email"));
    ASSERT_FALSE(userService.registerUser("username2", "password2", "fullName2", "role2", "department2", "email2"));
    ASSERT_FALSE(userService.registerUser("username3", "password3", "fullName", "role", "department", "email"));
    ASSERT_FALSE(userService.registerUser("username", "password2", "fullName", "role", "department", "email"));
    ASSERT_FALSE(userService.registerUser("username2", "password", "fullName2", "role2", "department2", "email2"));
    ASSERT_TRUE(userService.deleteUser("username"));
    ASSERT_TRUE(userService.deleteUser("username2"));
    ASSERT_TRUE(userService.deleteUser("username3"));
    ASSERT_FALSE(userService.deleteUser("username"));
}

TEST(UserServiceTest, authenticateUser)
{
    UserService userService;
    ASSERT_TRUE(userService.registerUser("username", "password", "fullName", "role", "department", "email"));
    ASSERT_TRUE(userService.authenticateUser(userService.hashPassword("password"), "username"));
    ASSERT_FALSE(userService.authenticateUser(userService.hashPassword("password2"), "username"));
    ASSERT_FALSE(userService.authenticateUser(userService.hashPassword("password"), "username2"));
    ASSERT_FALSE(userService.authenticateUser(userService.hashPassword("password2"), "username2"));
    ASSERT_TRUE(userService.deleteUser("username"));
}

TEST(UserServiceTest, login)
{
    UserService userService;
    ASSERT_TRUE(userService.registerUser("username", "password", "fullName", "role", "department", "email"));
    ASSERT_TRUE(userService.login("password", "username"));
    ASSERT_FALSE(userService.login("password2", "username"));
    ASSERT_FALSE(userService.login("password", "username2"));
    ASSERT_FALSE(userService.login("password2", "username2"));
    ASSERT_TRUE(userService.deleteUser("username"));
}

TEST(UserServiceTest, logout)
{
    UserService userService;
    ASSERT_TRUE(userService.registerUser("username", "password", "fullName", "role", "department", "email"));
    ASSERT_TRUE(userService.login("password", "username"));
    ASSERT_TRUE(userService.logout());
    ASSERT_FALSE(userService.logout());
    ASSERT_TRUE(userService.deleteUser("username"));
}

TEST(UserServiceTest, changePassword)
{
    UserService userService;
    ASSERT_TRUE(userService.registerUser("username", "password", "fullName", "role", "department", "email"));
    ASSERT_TRUE(userService.login("password", "username"));
    ASSERT_TRUE(userService.changePassword("newPassword"));
    ASSERT_TRUE(userService.login("newPassword", "username"));
    ASSERT_FALSE(userService.login("password", "username"));
    ASSERT_TRUE(userService.deleteUser("username"));
}

TEST(UserServiceTest, viewProfile)
{
    UserService userService;
    ASSERT_TRUE(userService.registerUser("username", "password", "fullName", "role", "department", "email"));
    ASSERT_TRUE(userService.login("password", "username"));
    ASSERT_NO_THROW(userService.viewProfile());
    ASSERT_TRUE(userService.deleteUser("username"));
}

TEST(UserServiceTest, updateUserProfile)
{
    UserService userService;
    ASSERT_TRUE(userService.registerUser("username", "password", "fullName", "role", "department", "email"));
    ASSERT_TRUE(userService.login("password", "username"));
    ASSERT_TRUE(userService.updateUserProfile("newFullName", "newEmail", "newRole", "newDepartment"));
    ASSERT_NO_THROW(userService.viewProfile());
    ASSERT_TRUE(userService.deleteUser("username"));
}

TEST(UserServiceTest, hashPassword)
{
    UserService userService;
    ASSERT_NE(userService.hashPassword("password"), "password");
}
