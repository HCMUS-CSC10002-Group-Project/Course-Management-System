#ifndef USER_H
#define USER_H

#include <string>

using std::string;

class User
{
protected:
    // user data
    string ID;
    string role;
    string first_name;
    string last_name;
    string full_name;
    string department;
    string email;
    string username;
    string password;

public:
    // constructor
    User(string role, string fullName, string department, string email, string username, string password);
    User(string ID, string role, string fullName, string department, string email, string username, string password);

    // getters and setters
    string getID();
    string getFirstName();
    string getLastName();
    string getFullName();
    string getRole();
    string getDepartment();
    string getEmail();
    string getUsername();
    string getPassword();
    bool setRole(string newRole);
    bool setFullName(string newFullName);
    bool setDepartment(string newDepartment);
    bool setEmail(string newEmail);
    bool setPassword(string newPassword);
    // serialization
    string serialize();
    static User deserialize(const string &serialized);
    string getHeader();
};

#endif // USER_H
