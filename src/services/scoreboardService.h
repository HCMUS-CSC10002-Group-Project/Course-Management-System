#ifndef SCOREBOARD_SERVICE_H
#define SCOREBOARD_SERVICE_H

#include "../entities/scoreboard.h"
#include "../entities/student.h"
#include "../data_structures/LinkedList.h"

class ScoreboardService
{
    public:
        bool setScore(map<Student,DetailedScore> scoreSheet, float score, string scoreType);
        // scoreType is to know whether the score is for midterms, finals, etc.)
        Scoreboard viewCourseScoreboard(string courseID);
        LinkedList<Scoreboard> viewClassScoreboard(string classID);
};

#endif SCOREBOARD_SERVICE_H
