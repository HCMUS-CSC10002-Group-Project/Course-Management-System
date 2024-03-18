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
        LinkedList<semester> semesters;
    public:
        //getters
        string getyearID();
        Date getStartDate();
        Date getEndDate();
        LinkedList<semester> getSemesters();
        //setters
        void setStartDate(Date newStartDate);
        void setEndDate(Date newEndDate);
        void removeSemester(semester semester.semester_ID);
        void addSemester(semester semester.semester_ID);
        //methods
        bool getNumSemester(LinkedList<semester> listOfSemester);
        bool addSemester(semester semester);
};
#endif