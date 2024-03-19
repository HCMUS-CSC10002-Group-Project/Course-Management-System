#ifndef SCHOOLYEAR_H
#define SCHOOLYEAR_H
#include "semester.h"
#include "date.h"
#include <string>
#include "../data_structures/LinkedList.h"
using std::string;
class SchoolYear
{
    private: 
        string year_ID;
        Date start_date;
        Date end_date;
        LinkedList<Semester> semesters;
    public:
        //getters
        string getyearID();
        Date getStartDate();
        Date getEndDate();
        LinkedList<Semester> getSemesters();
        //setters
        bool setStartDate(Date newStartDate);
        bool setEndDate(Date newEndDate);
        //methods
        int getNumSemester();
        bool addSemester(Semester semester);
        bool removeSemester(Semester semester);
        //constructor
        SchoolYear(Date start_date, Date end_date);
};
#endif
