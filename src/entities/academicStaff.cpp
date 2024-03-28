#include "academicStaff.h"
#include "../utils/StringUtils.h"
#include "../utils/UUID.h"

AcademicStaff::AcademicStaff(string fullName, string department, string email, string username, string password)
    : User("staff", fullName, department, email, username, password)
{
    staff_ID = UUIDGenerator::generate();
}

AcademicStaff::AcademicStaff(string ID, string fullName, string department, string email, string username, string password, string staff_ID)
    : User(ID, "staff", fullName, department, email, username, password)
{
    this->staff_ID = staff_ID;
}

string AcademicStaff::getStaffID()
{
    return staff_ID;
}

string AcademicStaff::serialize()
{
    string serialized = ID + "," + full_name + "," + department + "," + email + "," + username + "," + password + "," + staff_ID;
    return serialized;
}

AcademicStaff AcademicStaff::deserialize(const string &serialized)
{
    DynamicArray<string> data = split(serialized, ',');
    return AcademicStaff(data.Get(0), data.Get(1), data.Get(2), data.Get(3), data.Get(4), data.Get(5), data.Get(6));
}

string AcademicStaff::getHeader()
{
    return "ID,Full Name,Department,Email,Username,Password,Staff ID";
}