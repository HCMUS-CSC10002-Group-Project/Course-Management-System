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
    string semester_name;
    Date start_date;
    Date end_date;

public:
    // getter
    string getSemesterID();
    string getYearID();
    string getSemesterName();
    Date getStartDate();
    Date getEndDate();
    // setter
    bool setStartDate(Date newStartDate);
    bool setEndDate(Date newEndDate);
    bool setSemesterName(string newSemesterName);
    // constructor
    Semester(string year_ID, string semester_name, Date start_date, Date end_date);
    Semester(string semester_ID, string year_ID, string semester_name, Date start_date, Date end_date);

    // serializer and deserializer
    string serialize();
    static Semester deserialize(const string &serialized);
    string getHeader();
};
#endif