#ifndef SEMESTER_H
#define SEMESTER_H 

#include <string>
#include "Date.h"
#include "../data_structures/LinkedList.h"
using std::string;
class Semester
{
    private:
        string semester_ID;
        string year_ID;
        int semester_number;
        Date start_date;
        Date end_Date;
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