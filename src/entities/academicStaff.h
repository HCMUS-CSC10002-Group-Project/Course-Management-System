#ifndef ACADEMIC_STAFF_H
#define ACADEMIC_STAFF_H

#include "user.h"

class AcademicStaff : public User
{
    private:
        string staff_ID;
    public:
        string getStaffID();
        bool setStaffID(string newID);
};

#endif ACADEMIC_STAFF_H
