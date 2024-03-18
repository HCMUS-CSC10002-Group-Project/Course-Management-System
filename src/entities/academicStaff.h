#ifndef ACADEMIC_STAFF_H
#define ACADEMIC_STAFF_H

#include "user.h"

class AcademicStaff : public User
{
    private:
        string staff_ID;
    public:
        string getStaffID();
};

#endif ACADEMIC_STAFF_H
