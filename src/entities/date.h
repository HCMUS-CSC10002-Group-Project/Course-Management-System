#ifndef DATE_H
#define DATE_H
class Date
{
    private:
        int year;
        int month;
        int date;
    public:
    //getters
    int getDate();
    int getMonth();
    int getYear();
    //setters
    bool setYear(int newDate);
    bool setMonth(int newMonth);
    bool setDate(int newDate);
    //constructor
    Date(int year, int month, int date);
};
#endif


