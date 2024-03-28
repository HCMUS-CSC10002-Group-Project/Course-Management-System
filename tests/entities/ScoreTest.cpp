#include "gtest/gtest.h"
#include "scoreboard.h"
#include "detailedScore.h"

TEST(Scoreboard, Constructor)
{
    Scoreboard scoreboard("C01");
    EXPECT_EQ(scoreboard.getCourseID(), "C01");
}

TEST(Scoreboard, ConstructorWithScores)
{
    map<string, DetailedScore> scores;
    scores["S01"] = DetailedScore(1.0, 2.0, 3.0, 4.0);
    scores["S02"] = DetailedScore(5.0, 6.0, 7.0, 8.0);
    Scoreboard scoreboard("C01", scores);
    EXPECT_EQ(scoreboard.getCourseID(), "C01");
    EXPECT_EQ(scoreboard.getScores().size(), 2);
    EXPECT_EQ(scoreboard.getScores()["S01"].getOtherMark(), 1.0);
    EXPECT_EQ(scoreboard.getScores()["S01"].getMidtermMark(), 2.0);
    EXPECT_EQ(scoreboard.getScores()["S01"].getFinalMark(), 3.0);
    EXPECT_EQ(scoreboard.getScores()["S01"].geTotalMark(), 4.0);
    EXPECT_EQ(scoreboard.getScores()["S02"].getOtherMark(), 5.0);
    EXPECT_EQ(scoreboard.getScores()["S02"].getMidtermMark(), 6.0);
    EXPECT_EQ(scoreboard.getScores()["S02"].getFinalMark(), 7.0);
    EXPECT_EQ(scoreboard.getScores()["S02"].geTotalMark(), 8.0);
}

TEST(Scoreboard, Serialize)
{
    map<string, DetailedScore> scores;
    scores["S01"] = DetailedScore(1, 2, 3, 4);
    scores["S02"] = DetailedScore(5, 6, 7, 8);
    Scoreboard scoreboard("C01", scores);
    string serialized = scoreboard.serialize();
    EXPECT_EQ(serialized, "C01,S01#1.0;2.0;3.0;4.0,S02#5.0;6.0;7.0;8.0");
}

TEST(Scoreboard, Deserialize)
{
    Scoreboard scoreboard = Scoreboard::deserialize("C01,S01#1.0;2.0;3.0;4.0,S02#5.0;6.0;7.0;8.0");
    EXPECT_EQ(scoreboard.getCourseID(), "C01");
    EXPECT_EQ(scoreboard.getScores().size(), 2);
    EXPECT_EQ(scoreboard.getScores()["S01"].getOtherMark(), 1.0);
    EXPECT_EQ(scoreboard.getScores()["S01"].getMidtermMark(), 2.0);
    EXPECT_EQ(scoreboard.getScores()["S01"].getFinalMark(), 3.0);
    EXPECT_EQ(scoreboard.getScores()["S01"].geTotalMark(), 4.0);
    EXPECT_EQ(scoreboard.getScores()["S02"].getOtherMark(), 5.0);
    EXPECT_EQ(scoreboard.getScores()["S02"].getMidtermMark(), 6.0);
    EXPECT_EQ(scoreboard.getScores()["S02"].getFinalMark(), 7.0);
    EXPECT_EQ(scoreboard.getScores()["S02"].geTotalMark(), 8.0);
}

TEST(Scoreboard, DeserializeEmpty)
{
    Scoreboard scoreboard = Scoreboard::deserialize("C01");
    EXPECT_EQ(scoreboard.getCourseID(), "C01");
    EXPECT_EQ(scoreboard.getScores().size(), 0);
}