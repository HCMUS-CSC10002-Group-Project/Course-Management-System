#include <string>
#include "../services/userService.h"

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
        string getFIrstName();
        string getLastName();
        string getFullName();
        void setFullName();
        string getDepartment();
        void setDepartment();
        string getEmail();
        void setEmail();
        string getUsername();
};
