#include "schoolYear.h"
#include "../utils/StringUtils.h"
#include "../utils/UUID.h"

SchoolYear::SchoolYear(Date start_date, Date end_date)
{
    year_ID = UUIDGenerator::generate();
    this->start_date = start_date;
    this->end_date = end_date;
}

SchoolYear::SchoolYear(string year_ID, Date start_date, Date end_date, LinkedList<string> semester_IDs)
{
    this->year_ID = year_ID;
    this->start_date = start_date;
    this->end_date = end_date;
    this->semester_IDs = semester_IDs;
}

string SchoolYear::getYearID()
{
    return year_ID;
}

Date SchoolYear::getStartDate()
{
    return start_date;
}

Date SchoolYear::getEndDate()
{
    return end_date;
}

LinkedList<string> SchoolYear::getSemesterIDs()
{
    return semester_IDs;
}

int SchoolYear::getNumSemester()
{
    return semester_IDs.Size();
}

string SchoolYear::serialize()
{
    string serialized = year_ID + "," + start_date.serialize() + "," + end_date.serialize() + ",";
    for (int i = 0; i < semester_IDs.Size(); i++)
    {
        serialized += semester_IDs.Get(i);
        if (i < semester_IDs.Size() - 1)
        {
            serialized += ';';
        }
    }
    return serialized;
}

SchoolYear SchoolYear::deserialize(const string &serialized)
{
    DynamicArray<string> data = split(serialized, ',');
    string year_ID = data.Get(0);
    Date start_date = Date::deserialize(data.Get(1));
    Date end_date = Date::deserialize(data.Get(2));
    LinkedList<string> semester_IDs;
    DynamicArray<string> semester_IDs_data = split(data.Get(3), ';');
    for (int i = 0; i < semester_IDs_data.Size(); i++)
    {
        semester_IDs.AddToEnd(semester_IDs_data.Get(i));
    }
    return SchoolYear(year_ID, start_date, end_date, semester_IDs);
}

string SchoolYear::getHeader()
{
    return "Year ID,Start Date,End Date,Semester IDs";
}
