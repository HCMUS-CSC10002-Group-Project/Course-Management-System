#ifndef USER_H
#define USER_H

#include <string>

using std::string;

class User
{
    private:
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
        void setFullName(string newFullName);
        string getDepartment();
        void setDepartment(string newDepartment);
        string getEmail();
        void setEmail(string newEmail);
        string getUsername();
};

#endif //USER_H
