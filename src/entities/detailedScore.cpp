#include "detailedScore.h"
#include "../utils/StringUtils.h"
#include "../utils/UUID.h"
#include <sstream>
#include <iomanip>

DetailedScore::DetailedScore(float otherMark, float midtermMark, float finalMark, float totalMark)
{
    this->other_mark = otherMark;
    this->midterm_mark = midtermMark;
    this->final_mark = finalMark;
    this->total_mark = totalMark;
}

DetailedScore::DetailedScore()
{
    this->other_mark = 0;
    this->midterm_mark = 0;
    this->final_mark = 0;
    this->total_mark = 0;
}

float DetailedScore::getOtherMark()
{
    return other_mark;
}

float DetailedScore::getMidtermMark()
{
    return midterm_mark;
}

float DetailedScore::getFinalMark()
{
    return final_mark;
}

float DetailedScore::geTotalMark()
{
    return total_mark;
}

float DetailedScore::calcTotalMark()
{
    return 0.1 * other_mark + 0.3 * midterm_mark + 0.6 * final_mark;
}

bool DetailedScore::setOtherMark(float newOtherMark)
{
    if (newOtherMark < 0 || newOtherMark > 10)
    {
        return false;
    }
    other_mark = newOtherMark;
    return true;
}

bool DetailedScore::setMidtermMark(float newMidtermMark)
{
    if (newMidtermMark < 0 || newMidtermMark > 10)
    {
        return false;
    }
    midterm_mark = newMidtermMark;
    return true;
}

bool DetailedScore::setFinalMark(float newFinalMark)
{
    if (newFinalMark < 0 || newFinalMark > 10)
    {
        return false;
    }
    final_mark = newFinalMark;
    return true;
}

string DetailedScore::serialize()
{
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(1) << other_mark << ";" << midterm_mark << ";" << final_mark << ";" << total_mark;
    return oss.str();
}

DetailedScore DetailedScore::deserialize(const string &serialized)
{
    auto parts = split(serialized, ';');
    return DetailedScore(std::stof(parts.Get(0)), std::stof(parts.Get(1)), std::stof(parts.Get(2)), std::stof(parts.Get(3)));
}