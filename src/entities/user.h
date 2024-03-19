#ifndef USER_H
#define USER_H

#include <string>

using std::string;

class User
{
    protected:
        //user data
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
        //constructor
        User(string role, string fullName, string department, string email, string username, string password);

        //getters and setters
        string getID();
        string getFirstName();
        string getLastName();
        string getFullName();
        bool setFullName(string newFullName);
        string getDepartment();
        bool setDepartment(string newDepartment);
        string getEmail();
        bool setEmail(string newEmail);
        string getUsername();
};

#endif //USER_H
