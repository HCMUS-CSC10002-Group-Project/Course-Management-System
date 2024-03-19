#ifndef SCOREBOARD_H
#define SCOREBOARD_H
#include <string>
#include "student.h"
#include "detailedScore.h"
using std::string;
class Scoreboard
{
    private:
        string course_ID;
    public:
    //getters
    string getCourseID();
    //methods
    void addScore(Student student, DetailedScore detailedScore);
    void updateStudentResult(Student student, DetailedSocre detailedScore);
    //constructor
    Scoreboard(string course_ID);
};
#endif