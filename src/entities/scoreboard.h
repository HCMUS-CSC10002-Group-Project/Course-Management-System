#ifndef SCOREBOARD_H
#define SCOREBOARD_H
#include <string>
using std::string;
class Scoreboard
{
    private:
        string course_ID;
    public:
    //getters
    string getCourseID();
    //setters
    void setCourseID(string newCourseID);
    //methods
    void addScore();
};
#endif