#ifndef DETAILEDSCORE_H
#define DETAILEDSCORE_H
#include <map>
#include <string>
#include "student.h"
using std::string;
class DetailedScore
{
    private:
    float midterm_mark;
    float final_mark;
    float total_mark;
    map<string, float> other_marks;

    public:
    //getters
    float getMidtermMark();
    float getFinalMark();
    float geTotalMark();
    float calcTotalMark();
    //setters
    bool setMidtermMark(float newMidtermMark);
    bool setFinalMark(float newFinalMark);
    //constructors
    DetailedScore(float midtermMark, float finalMark, float totalMark, map<string, float> otherMarks);
};
#endif