#ifndef USER_SERVICE_H
#define USER_SERVICE_H

#include "../entities/user.h"

class UserService
{
public:
    bool authenticateUser(string passwordHash, string username);
    bool login(string password, string username);
    bool logout();
    bool registerUser(string username, string password, string fullName, string role, string department, string email);
    bool changePassword(string newPassword);
    void viewProfile();
    bool deleteUser(string username);
    virtual bool updateUserProfile(string newFullName, string newEmail, string newRole, string newDepartment);
    string hashPassword(string password);
};

#endif // USER_SERVICE_H
