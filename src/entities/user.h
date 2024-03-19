#ifndef USER_H
#define USER_H

#include <string>

using std::string;

class User
{
    protected:
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
