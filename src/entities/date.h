#ifndef DATE_H
#define DATE_H
#include <string>
class Date
{
private:
    int day;
    int month;
    int year;

public:
    bool isValid();
    // getters
    int getDay();
    int getMonth();
    int getYear();

    // setters
    bool setYear(int newYear);
    bool setMonth(int newMonth);
    bool setDay(int newDay);

    // constructor
    Date();
    Date(int day, int month, int year);

    // serialization
    std::string serialize();
    static Date deserialize(const std::string &serialized);
};
#endif
