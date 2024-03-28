#ifndef SCOREBOARD_H
#define SCOREBOARD_H
#include <string>
#include "student.h"
#include "detailedScore.h"
#include <map>
using std::string;
class Scoreboard
{
private:
    string course_ID;
    map<string, DetailedScore> scores;

public:
    // constructors
    Scoreboard(string course_ID);
    Scoreboard(string course_ID, map<string, DetailedScore> scores);
    // getters
    string getCourseID();
    map<string, DetailedScore> getScores();
    // methods
    void addScore(string student_ID, DetailedScore detailedScore);
    void updateStudentResult(string student_ID, DetailedScore detailedScore);
    // serialization
    string serialize();
    static Scoreboard deserialize(string data);
    string getHeader();
};
#endif