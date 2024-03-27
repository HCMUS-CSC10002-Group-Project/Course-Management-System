#include "scoreboard.h"
#include "detailedScore.h"
#include "../utils/StringUtils.h"

Scoreboard::Scoreboard(string course_ID)
{
    this->course_ID = course_ID;
}

Scoreboard::Scoreboard(string course_ID, map<string, DetailedScore> scores)
{
    this->course_ID = course_ID;
    this->scores = scores;
}

string Scoreboard::getCourseID()
{
    return course_ID;
}

map<string, DetailedScore> Scoreboard::getScores()
{
    return scores;
}

string Scoreboard::serialize()
{
    string data = course_ID + ",";
    for (auto const &score : scores)
    {
        data += score.first + "#";
        DetailedScore detailedScore = score.second;
        data += detailedScore.serialize();
        if (score.first != scores.rbegin()->first)
        {
            data += ",";
        }
    }
    return data;
}

Scoreboard Scoreboard::deserialize(string data)
{
    DynamicArray<string> parts = split(data, ',');
    string course_ID = parts.Get(0);
    map<string, DetailedScore> scores;
    for (int i = 1; i < parts.Size(); i++)
    {
        DynamicArray<string> scoreParts = split(parts.Get(i), '#');
        string student_ID = scoreParts.Get(0);
        DetailedScore detailedScore = DetailedScore::deserialize(scoreParts.Get(1));
        scores[student_ID] = detailedScore;
    }
    return Scoreboard(course_ID, scores);
}

string Scoreboard::getHeader()
{
    return "Course ID, Detailed Scores";
}