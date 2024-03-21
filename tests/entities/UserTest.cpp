#include <gtest/gtest.h>
#include "user.h"

using namespace std;

TEST(UserTest, TestUserGet)
{
    User user("staff", "John Doe", "IT", "baba@gmail.com", "baba", "password");
    ASSERT_NE(user.getID(), "");
    ASSERT_EQ("staff", user.getRole());
    ASSERT_EQ("John", user.getFirstName());
    ASSERT_EQ("Doe", user.getLastName());
    ASSERT_EQ("John Doe", user.getFullName());
    ASSERT_EQ("IT", user.getDepartment());
    ASSERT_EQ("baba", user.getUsername());
}

TEST(UserTest, TestSetFullName)
{
    User user("student", "John MoMo Doe", "ITabc", "asdfasdf@gmail.com", "huhulala", "thisisapassword");
    EXPECT_TRUE(user.setFullName("John MaMa Doe"));
    ASSERT_EQ("John MaMa Doe", user.getFullName());
    ASSERT_EQ("Doe", user.getFirstName());
    ASSERT_EQ("John", user.getLastName());
    EXPECT_TRUE(user.setFullName("Cây"));
    ASSERT_EQ("Cây", user.getFullName());
    ASSERT_EQ("", user.getLastName());
    ASSERT_EQ("Cây", user.getFirstName());
    EXPECT_TRUE(user.setFullName("Cây Đẹp Trai"));
    ASSERT_EQ("Cây Đẹp Trai", user.getFullName());
    ASSERT_EQ("Cây", user.getLastName());
    ASSERT_EQ("Trai", user.getFirstName());
    EXPECT_TRUE(user.setFullName("Nguyễn Văn Trồng Cây"));
    ASSERT_EQ("Nguyễn Văn Trồng Cây", user.getFullName());
    ASSERT_EQ("Nguyễn", user.getLastName());
    ASSERT_EQ("Cây", user.getFirstName());
    EXPECT_FALSE(user.setFullName(""));
}

TEST(UserTest, TestSetDepartment)
{
    User user("student", "John MoMo Doe", "ITabc", "ababa@gmail.com", "huhulala", "thisisapassword");
    EXPECT_TRUE(user.setDepartment("IT"));
    ASSERT_EQ("IT", user.getDepartment());
    EXPECT_TRUE(user.setDepartment("IT Department"));
    ASSERT_EQ("IT Department", user.getDepartment());
    EXPECT_FALSE(user.setDepartment(""));
}

TEST(UserTest, TestSetEmail)
{
    User user("student", "John MoMo Doe", "ITabc", "bababa@gmail.com", "huhulala", "thisisapassword");
    EXPECT_TRUE(user.setEmail("123@gmail.com"));
    ASSERT_EQ(user.getEmail(), "123@gmail.com");
    EXPECT_TRUE(user.setEmail("a@gmail.com"));
    ASSERT_EQ(user.getEmail(), "a@gmail.com");
    EXPECT_FALSE(user.setEmail(""));
    EXPECT_EQ(user.getEmail(), "a@gmail.com");
    EXPECT_FALSE(user.setEmail("a"));
    EXPECT_EQ(user.getEmail(), "a@gmail.com");
    EXPECT_FALSE(user.setEmail("a@"));
    EXPECT_FALSE(user.setEmail("a@."));
    EXPECT_FALSE(user.setEmail("a@.a"));
    EXPECT_FALSE(user.setEmail("a@.a."));
    EXPECT_EQ(user.getEmail(), "a@gmail.com");
}

TEST(UserTest, TestDuplicatedEmail)
{
    User user1("student", "John MoMo Doe", "ITabc", "baba@gmail.com", "huhulala", "thisisapassword");
    User user2("student", "John MoMo Doe", "ITabc", "bobo@gmail.com", "mana", "thisissuperpassword");
    EXPECT_FALSE(user2.setEmail("baba@gmail.com"));
    EXPECT_EQ(user2.getEmail(), "bobo@gmail.com");
    EXPECT_FALSE(user1.setEmail("bobo@gmail.com"));
    EXPECT_EQ(user1.getEmail(), "baba@gmail.com");
    EXPECT_TRUE(user1.setEmail("bubu@gmail.com"));
    EXPECT_EQ(user1.getEmail(), "bubu@gmail.com");
    EXPECT_TRUE(user2.setEmail("baba@gmail.com"));
    EXPECT_EQ(user2.getEmail(), "baba@gmail.com");
    EXPECT_TRUE(user1.setEmail("bobo@gmail.com"));
    EXPECT_EQ(user1.getEmail(), "bobo@gmail.com");
    EXPECT_FALSE(user1.setEmail("baba@gmail.com"));
}
