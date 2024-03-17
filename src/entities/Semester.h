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
        int semester_number;
        Date start_date;
        Date end_date;
    public:
        //getter
        string getSemesterID();
        string getYearID();
        int getSemesterNumber();
        Date getStartDate();
        Date getEndDate();
        //setter
        void setSemesteID(string newSemesterID);
        void setYearID(string newYearID);
        void setSemesterNumber(string newSemesterNumber);
        void setStartDate(Date newStartDate);
        void setEndDate(Date newEndDate);
};
#endif