#include "date.h"
#include "../utils/StringUtils.h"
#include <string>

using std::string;

Date::Date()
{
    this->day = 1;
    this->month = 1;
    this->year = 2024;
}

Date::Date(int day, int month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}

bool Date::isValid()
{
    if (year < 0)
        return false;
    if (month < 1 || month > 12)
        return false;

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
    {
        daysInMonth[1] = 29;
    }

    return day > 0 && day <= daysInMonth[month - 1];
}

int Date::getDay()
{
    return this->day;
}

int Date::getMonth()
{
    return this->month;
}

int Date::getYear()
{
    return this->year;
}

bool Date::setYear(int newYear)
{
    if (newYear < 0)
    {
        return false;
    }
    this->year = newYear;
    return true;
}

bool Date::setMonth(int newMonth)
{
    if (newMonth < 1 || newMonth > 12)
    {
        return false;
    }
    this->month = newMonth;
    return true;
}

bool Date::setDay(int newDay)
{
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (this->month == 2 && ((this->year % 4 == 0 && this->year % 100 != 0) || (this->year % 400 == 0)))
    {
        daysInMonth[1] = 29;
    }
    if (newDay < 1 || newDay > daysInMonth[this->month - 1])
    {
        return false;
    }
    this->day = newDay;
    return true;
}

string Date::serialize()
{
    return to_string(this->day) + "-" + to_string(this->month) + "-" + to_string(this->year);
}

Date Date::deserialize(const string &serialized)
{
    DynamicArray<string> data = split(serialized, '-');
    int day = stoi(data.Get(0));
    int month = stoi(data.Get(1));
    int year = stoi(data.Get(2));
    return Date(day, month, year);
}