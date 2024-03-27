#ifndef ACADEMIC_STAFF_H
#define ACADEMIC_STAFF_H

#include "user.h"

class AcademicStaff : public User
{
private:
    string staff_ID;

public:
    AcademicStaff(string fullName, string department, string email, string username, string password);
    AcademicStaff(string ID, string fullName, string department, string email, string username, string password, string staff_ID);
    string getStaffID();

    // serialization
    string serialize();
    static AcademicStaff deserialize(const string &serialized);
    string getHeader();
};

#endif // ACADEMIC_STAFF_H
