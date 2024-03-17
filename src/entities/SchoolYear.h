#ifndef SCHOOLYEAR_H
#define SCHOOLYEAR_H
#include "Semester.h"
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
        void setStartDate(Date newStartDate);
        void setEndDate(Date newEndDate);
        void setListOfSemester(LinkedList<Semester> newList);
        //methods
        bool getNumSemester(LinkedList<Semester> listOfSemester);
        bool addSemester(Semester semester);
};
#endif