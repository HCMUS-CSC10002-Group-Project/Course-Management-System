#include "user.h"
#include "../utils/StringUtils.h"
#include "../utils/UUID.h"

User::User(string role, string fullName, string department, string email, string username, string password)
    : role(role), full_name(fullName), department(department), email(email), username(username), password(password)
{
    ID = UUIDGenerator::generate();
    DynamicArray<string> name = split(fullName, ' ');
    first_name = name.Get(name.Size() - 1);
    last_name = name.Get(0);
}

User::User(string ID, string role, string fullName, string department, string email, string username, string password)
    : ID(ID), role(role), full_name(fullName), department(department), email(email), username(username), password(password)
{
    DynamicArray<string> name = split(fullName, ' ');
    first_name = name.Get(name.Size() - 1);
    last_name = name.Get(0);
}

string User::serialize()
{
    return ID + "," + role + "," + full_name + "," + department + "," + email + "," + username + "," + password;
}

User User::deserialize(const string &serialized)
{
    DynamicArray<string> data = split(serialized, ',');
    return User(data.Get(0), data.Get(1), data.Get(2), data.Get(3), data.Get(4), data.Get(5), data.Get(6));
}

string User::getHeader()
{
    return "ID,Role,Full Name,Department,Email,Username,Password";
}

string User::getID()
{
    return ID;
}

string User::getFirstName()
{
    return first_name;
}

string User::getLastName()
{
    return last_name;
}

string User::getFullName()
{
    return full_name;
}

string User::getRole()
{
    return role;
}

bool User::setRole(string newRole)
{
    if (newRole.empty() || newRole == role)
        return false;
    role = newRole;
    return true;
}

string User::getDepartment()
{
    return department;
}

bool User::setDepartment(string newDepartment)
{
    if (newDepartment.empty() || newDepartment == department)
        return false;
    department = newDepartment;
    return true;
}

string User::getEmail()
{
    return email;
}

string User::getUsername()
{
    return username;
}

string User::getPassword()
{
    return password;
}
