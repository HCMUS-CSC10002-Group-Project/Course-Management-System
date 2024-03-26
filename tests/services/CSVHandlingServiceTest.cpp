#include <gtest/gtest.h>
#include "CSVHandlingService.h"
#include "user.h"
#include "StringUtils.h"
#include <fstream>
#include <sstream>
#include <iostream>

TEST(CSVHandlingServiceTest, ReadCSV)
{
    CSVHandlingService<User> csvService;
    string filePath = "../../data/users.csv";
    LinkedList<User> users = csvService.importFromCSV(filePath, User::deserialize);
    ASSERT_EQ(users.Size(), 3);
    ASSERT_EQ(users.Get(0).getID(), "1");
    ASSERT_EQ(users.Get(0).getRole(), "Admin");
    ASSERT_EQ(users.Get(0).getFullName(), "John Doe");
    ASSERT_EQ(users.Get(0).getDepartment(), "IT");
    ASSERT_EQ(users.Get(0).getEmail(), "aa@gmail.com");
    ASSERT_EQ(users.Get(0).getUsername(), "admin");
    ASSERT_EQ(users.Get(0).getPassword(), "admin");
    ASSERT_EQ(users.Get(0).getFirstName(), "Doe");
    ASSERT_EQ(users.Get(0).getLastName(), "John");
    ASSERT_EQ(users.Get(1).getID(), "2");
    ASSERT_EQ(users.Get(1).getRole(), "User");
    ASSERT_EQ(users.Get(1).getFullName(), "Jane Doe");
    ASSERT_EQ(users.Get(1).getDepartment(), "HR");
    ASSERT_EQ(users.Get(1).getEmail(), "bbaba@gmail.com");
    ASSERT_EQ(users.Get(1).getUsername(), "user");
    ASSERT_EQ(users.Get(1).getPassword(), "user");
    ASSERT_EQ(users.Get(1).getFirstName(), "Doe");
    ASSERT_EQ(users.Get(1).getLastName(), "Jane");
    ASSERT_EQ(users.Get(2).getID(), "3");
    ASSERT_EQ(users.Get(2).getRole(), "User");
    ASSERT_EQ(users.Get(2).getFullName(), "John Smith");
    ASSERT_EQ(users.Get(2).getDepartment(), "Finance");
    ASSERT_EQ(users.Get(2).getEmail(), "c@gmail.com");
    ASSERT_EQ(users.Get(2).getUsername(), "user22");
    ASSERT_EQ(users.Get(2).getPassword(), "user22");
    ASSERT_EQ(users.Get(2).getFirstName(), "Smith");
    ASSERT_EQ(users.Get(2).getLastName(), "John");
}

TEST(CSVHandlingServiceTest, WriteCSV)
{
    CSVHandlingService<User> csvService;
    string filePath = "../../data/users.csv";
    LinkedList<User> users = csvService.importFromCSV(filePath, User::deserialize);
    User user("4", "User", "Jane Smith", "Finance", "a@gmail.com", "user33", "user33");
    users.AddToEnd(user);
    csvService.exportToCSV(users, filePath);
    LinkedList<User> newUsers = csvService.importFromCSV(filePath, User::deserialize);
    ASSERT_EQ(newUsers.Size(), 4);
    ASSERT_EQ(newUsers.Get(3).getID(), "4");
    ASSERT_EQ(newUsers.Get(3).getRole(), "User");
    ASSERT_EQ(newUsers.Get(3).getFullName(), "Jane Smith");
    ASSERT_EQ(newUsers.Get(3).getDepartment(), "Finance");
    ASSERT_EQ(newUsers.Get(3).getEmail(), "a@gmail.com");
    ASSERT_EQ(newUsers.Get(3).getUsername(), "user33");
    ASSERT_EQ(newUsers.Get(3).getPassword(), "user33");
    ASSERT_EQ(newUsers.Get(3).getFirstName(), "Smith");
    ASSERT_EQ(newUsers.Get(3).getLastName(), "Jane");
    csvService.deleteFromCSV("4", filePath);
}

TEST(CSVHandlingServiceTest, AppendCSV)
{
    CSVHandlingService<User> csvService;
    string filePath = "../../data/users.csv";
    User user("4", "User", "Bao Vuong", "Meomeo", "meomeo@gmail.com", "user123", "user123");
    csvService.appendToCSV(user, filePath);
    LinkedList<User> newUsers = csvService.importFromCSV(filePath, User::deserialize);
    ASSERT_EQ(newUsers.Size(), 4);
    ASSERT_EQ(newUsers.Get(3).getID(), "4");
    ASSERT_EQ(newUsers.Get(3).getRole(), "User");
    ASSERT_EQ(newUsers.Get(3).getFullName(), "Vbee Vuong");
    ASSERT_EQ(newUsers.Get(3).getDepartment(), "Meomeo");
    ASSERT_EQ(newUsers.Get(3).getEmail(), "meomeo@gmail.com");
    ASSERT_EQ(newUsers.Get(3).getUsername(), "user123");
    ASSERT_EQ(newUsers.Get(3).getPassword(), "user123");
    ASSERT_EQ(newUsers.Get(3).getFirstName(), "Vuong");
    ASSERT_EQ(newUsers.Get(3).getLastName(), "Vbee");
    csvService.deleteFromCSV("4", filePath);
}