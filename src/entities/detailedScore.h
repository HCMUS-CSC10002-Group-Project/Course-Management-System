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
    float other_mark;

public:
    // getters
    float getOtherMark();
    float getMidtermMark();
    float getFinalMark();
    float geTotalMark();
    float calcTotalMark();
    // setters
    bool setOtherMark(float newOtherMark);
    bool setMidtermMark(float newMidtermMark);
    bool setFinalMark(float newFinalMark);
    // constructors
    DetailedScore();
    DetailedScore(float otherMark, float midtermMark, float finalMark, float totalMark);

    // serialization
    string serialize();
    static DetailedScore deserialize(const string &serialized);
};
#endif