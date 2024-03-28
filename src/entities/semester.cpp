#include "semester.h"
#include "../utils/StringUtils.h"
#include "../utils/UUID.h"

Semester::Semester(string year_ID, string semester_name, Date start_date, Date end_date)
{
    this->semester_ID = UUIDGenerator::generate();
    this->year_ID = year_ID;
    this->semester_name = semester_name;
    this->start_date = start_date;
    this->end_date = end_date;
}

Semester::Semester(string semester_ID, string year_ID, string semester_name, Date start_date, Date end_date)
{
    this->semester_ID = semester_ID;
    this->year_ID = year_ID;
    this->semester_name = semester_name;
    this->start_date = start_date;
    this->end_date = end_date;
}

string Semester::getSemesterID()
{
    return this->semester_ID;
}

string Semester::getYearID()
{
    return this->year_ID;
}

string Semester::getSemesterName()
{
    return this->semester_name;
}

Date Semester::getStartDate()
{
    return this->start_date;
}

Date Semester::getEndDate()
{
    return this->end_date;
}

bool Semester::setStartDate(Date newStartDate)
{
    if (newStartDate.isValid())
    {
        this->start_date = newStartDate;
        return true;
    }
    return false;
}

bool Semester::setEndDate(Date newEndDate)
{
    if (newEndDate.isValid())
    {
        this->end_date = newEndDate;
        return true;
    }
    return false;
}

bool Semester::setSemesterName(string newSemesterName)
{
    if (newSemesterName.length() > 0)
    {
        this->semester_name = newSemesterName;
        return true;
    }
    return false;
}

string Semester::serialize()
{
    return this->semester_ID + "," + this->year_ID + "," + this->semester_name + "," + this->start_date.serialize() + "," + this->end_date.serialize();
}

Semester Semester::deserialize(const string &serialized)
{
    DynamicArray<string> data = split(serialized, ',');
    return Semester(data.Get(0), data.Get(1), data.Get(2), Date::deserialize(data.Get(3)), Date::deserialize(data.Get(4)));
}

string Semester::getHeader()
{
    return "Semester ID,Year ID,Semester Name,Start Date,End Date";
}