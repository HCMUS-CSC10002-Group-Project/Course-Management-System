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
    void setYear(int newDate);
    void setMonth(int newMonth);
    void setDate(int newDate);
    //constructor
    Date(int year, int month, int date);
};
#endif


