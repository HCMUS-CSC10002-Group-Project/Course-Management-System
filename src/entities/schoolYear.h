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
    LinkedList<string> semester_IDs;

public:
    // constructor
    SchoolYear(Date start_date, Date end_date);
    SchoolYear(string year_ID, Date start_date, Date end_date, LinkedList<string> semester_IDs);
    // getters
    string getYearID();
    Date getStartDate();
    Date getEndDate();
    LinkedList<string> getSemesterIDs();
    // setters
    bool setStartDate(Date newStartDate);
    bool setEndDate(Date newEndDate);
    // methods
    int getNumSemester();
    bool addSemester(string semester_ID);
    bool removeSemester(string semester_ID);

    // serialization
    string serialize();
    static SchoolYear deserialize(const string &serialized);
    string getHeader();
};
#endif
