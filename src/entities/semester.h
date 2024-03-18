#ifndef SEMESTER_H
#define SEMESTER_H 

#include <string>
#include "date.h"
using std::string;
class Semester
{
    private:
        string semester_ID;
        string year_ID;
        Date start_date;
        Date end_date;
    public:
        //getter
        string getSemesterID();
        string getYearID();
        Date getStartDate();
        Date getEndDate();
        //setter
        bool setStartDate(Date newStartDate);
        bool setEndDate(Date newEndDate);
};
#endif