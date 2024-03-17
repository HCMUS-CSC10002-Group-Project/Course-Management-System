#ifndef SCHOOLYEAR_H
#define SCHOOLYEAR_H
#include "Semester.h"
#include "Date.h"
#include <string>
#include "../data_structures/LinkedList.h"
using std::string;
class SchoolYear
{
    private: 
        string year_ID;
        Date start_date;
        Date end_date;
        int max_semester;
        LinkedList<Semester> semesters;
    public:
        //getters
        string getyearID();
        Date getStartDate();
        Date getEndDate();
        int getMaxSemester();
        LinkedList<Semester> getSemesters();
        //setters
        void setYearID(string newYearID);
        void setStartDate(Date newStartDate);
        void setEndDate(Date newEndDate);
        void setMaxSemester(int newMaxSemester);
        void setListOfSemester(LinkedList<Semester> newList);
        //methods
        bool addSemester(Semester semester);
};
#endif