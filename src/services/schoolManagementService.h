#ifndef SCHOOL_MANAGEMENT_SERVICE_H
#define SCHOOL_MANAGEMENT_SERVICE_H

#include "../entities/schoolYear.h"

class SchoolManagementService
{
    public:
    bool createSchoolYear(Date start_date, Date end_date);
    bool createSemester(string year_ID, Date start_date, Date end_date);
    Semester getSemesterInfo(string semester_ID);
    SchoolYear getSchoolYearInfo(string year_ID);
};

#endif //SCHOOL_MANAGEMENT_SERVICE_H
