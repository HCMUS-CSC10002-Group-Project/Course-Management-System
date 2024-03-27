#include <gtest/gtest.h>
#include "CSVHandlingService.h"
#include "user.h"
#include "student.h"
#include "semester.h"
#include "date.h"
#include "class.h"
#include "course.h"
#include "academicStaff.h"
#include "scoreboard.h"
#include "schoolYear.h"
#include "StringUtils.h"
#include <fstream>
#include <sstream>
#include <iostream>

TEST(CSVHandlingServiceTest, ReadCSV)
{
    CSVHandlingService<User> csvService;
    string filePath = "../../data/users.csv";
    LinkedList<User> users = csvService.importFromCSV(filePath, User::deserialize);
    ASSERT_EQ(users.Size(), 3);
    ASSERT_EQ(users.Get(0).getID(), "1");
    ASSERT_EQ(users.Get(0).getRole(), "Admin");
    ASSERT_EQ(users.Get(0).getFullName(), "John Doe");
    ASSERT_EQ(users.Get(0).getDepartment(), "IT");
    ASSERT_EQ(users.Get(0).getEmail(), "aa@gmail.com");
    ASSERT_EQ(users.Get(0).getUsername(), "admin");
    ASSERT_EQ(users.Get(0).getPassword(), "admin");
    ASSERT_EQ(users.Get(0).getFirstName(), "Doe");
    ASSERT_EQ(users.Get(0).getLastName(), "John");
    ASSERT_EQ(users.Get(1).getID(), "2");
    ASSERT_EQ(users.Get(1).getRole(), "User");
    ASSERT_EQ(users.Get(1).getFullName(), "Jane Doe");
    ASSERT_EQ(users.Get(1).getDepartment(), "HR");
    ASSERT_EQ(users.Get(1).getEmail(), "bbaba@gmail.com");
    ASSERT_EQ(users.Get(1).getUsername(), "user");
    ASSERT_EQ(users.Get(1).getPassword(), "user");
    ASSERT_EQ(users.Get(1).getFirstName(), "Doe");
    ASSERT_EQ(users.Get(1).getLastName(), "Jane");
    ASSERT_EQ(users.Get(2).getID(), "3");
    ASSERT_EQ(users.Get(2).getRole(), "User");
    ASSERT_EQ(users.Get(2).getFullName(), "John Smith");
    ASSERT_EQ(users.Get(2).getDepartment(), "Finance");
    ASSERT_EQ(users.Get(2).getEmail(), "c@gmail.com");
    ASSERT_EQ(users.Get(2).getUsername(), "user22");
    ASSERT_EQ(users.Get(2).getPassword(), "user22");
    ASSERT_EQ(users.Get(2).getFirstName(), "Smith");
    ASSERT_EQ(users.Get(2).getLastName(), "John");
}

TEST(CSVHandlingServiceTest, WriteCSV)
{
    CSVHandlingService<User> csvService;
    string filePath = "../../data/users.csv";
    LinkedList<User> users = csvService.importFromCSV(filePath, User::deserialize);
    User user("4", "User", "Jane Smith", "Finance", "a@gmail.com", "user33", "user33");
    users.AddToEnd(user);
    csvService.exportToCSV(users, filePath);
    LinkedList<User> newUsers = csvService.importFromCSV(filePath, User::deserialize);
    ASSERT_EQ(newUsers.Size(), 4);
    ASSERT_EQ(newUsers.Get(3).getID(), "4");
    ASSERT_EQ(newUsers.Get(3).getRole(), "User");
    ASSERT_EQ(newUsers.Get(3).getFullName(), "Jane Smith");
    ASSERT_EQ(newUsers.Get(3).getDepartment(), "Finance");
    ASSERT_EQ(newUsers.Get(3).getEmail(), "a@gmail.com");
    ASSERT_EQ(newUsers.Get(3).getUsername(), "user33");
    ASSERT_EQ(newUsers.Get(3).getPassword(), "user33");
    ASSERT_EQ(newUsers.Get(3).getFirstName(), "Smith");
    ASSERT_EQ(newUsers.Get(3).getLastName(), "Jane");
    csvService.deleteFromCSV("4", filePath);
}

TEST(CSVHandlingServiceTest, AppendCSV)
{
    CSVHandlingService<User> csvService;
    string filePath = "../../data/users.csv";
    User user("4", "User", "Bao Vuong", "Meomeo", "meomeo@gmail.com", "user123", "user123");
    csvService.appendToCSV(user, filePath);
    LinkedList<User> newUsers = csvService.importFromCSV(filePath, User::deserialize);
    ASSERT_EQ(newUsers.Size(), 4);
    ASSERT_EQ(newUsers.Get(3).getID(), "4");
    ASSERT_EQ(newUsers.Get(3).getRole(), "User");
    ASSERT_EQ(newUsers.Get(3).getFullName(), "Bao Vuong");
    ASSERT_EQ(newUsers.Get(3).getDepartment(), "Meomeo");
    ASSERT_EQ(newUsers.Get(3).getEmail(), "meomeo@gmail.com");
    ASSERT_EQ(newUsers.Get(3).getUsername(), "user123");
    ASSERT_EQ(newUsers.Get(3).getPassword(), "user123");
    ASSERT_EQ(newUsers.Get(3).getFirstName(), "Vuong");
    ASSERT_EQ(newUsers.Get(3).getLastName(), "Bao");
    csvService.deleteFromCSV("4", filePath);
}

TEST(CSVHandlingServiceTest, ReadCSVStudent)
{
    CSVHandlingService<Student> csvService;
    string filePath = "../../data/students.csv";
    LinkedList<Student> students = csvService.importFromCSV(filePath, Student::deserialize);
    ASSERT_EQ(students.Size(), 1);
    ASSERT_EQ(students.Get(0).getID(), "1");
    ASSERT_EQ(students.Get(0).getRole(), "student");
    ASSERT_EQ(students.Get(0).getFullName(), "John Doe");
    ASSERT_EQ(students.Get(0).getDepartment(), "Computer Science");
    ASSERT_EQ(students.Get(0).getEmail(), "aa@gmail.com");
    ASSERT_EQ(students.Get(0).getUsername(), "johndoe");
    ASSERT_EQ(students.Get(0).getPassword(), "123");
    ASSERT_EQ(students.Get(0).getStudentID(), "1");
    ASSERT_EQ(students.Get(0).getClassID(), "2");
    ASSERT_EQ(students.Get(0).getCourseIDs().Size(), 5);
    ASSERT_EQ(students.Get(0).getCourseIDs().Get(0), "1");
    ASSERT_EQ(students.Get(0).getCourseIDs().Get(1), "2");
    ASSERT_EQ(students.Get(0).getCourseIDs().Get(2), "3");
    ASSERT_EQ(students.Get(0).getCourseIDs().Get(3), "5");
    ASSERT_EQ(students.Get(0).getCourseIDs().Get(4), "7");
    ASSERT_EQ(students.Get(0).getGender(), "male");
    ASSERT_EQ(students.Get(0).getDateOfBirth().serialize(), "1-1-1999");
    ASSERT_EQ(students.Get(0).getMajor(), "Computer Science");
    ASSERT_EQ(students.Get(0).getCohort(), "2020");
    ASSERT_EQ(students.Get(0).getSocialID(), "123");
}

TEST(CSVHandlingServiceTest, WriteCSVStudent)
{
    CSVHandlingService<Student> csvService;
    string filePath = "../../data/students.csv";
    LinkedList<Student> students = csvService.importFromCSV(filePath, Student::deserialize);
    LinkedList<string> courseIDs;
    courseIDs.AddToEnd("1");
    courseIDs.AddToEnd("6");
    courseIDs.AddToEnd("9");
    Student student("2", "Jane Doe", "HR", "b@gmail.com", "janedoe", "123", "2", "3", courseIDs, "female", Date(1, 1, 2000), "HR", "2021", "456");
    students.AddToEnd(student);
    csvService.exportToCSV(students, filePath);
    LinkedList<Student> newStudents = csvService.importFromCSV(filePath, Student::deserialize);
    ASSERT_EQ(newStudents.Size(), 2);
    ASSERT_EQ(newStudents.Get(1).getID(), "2");
    ASSERT_EQ(newStudents.Get(1).getRole(), "student");
    ASSERT_EQ(newStudents.Get(1).getFullName(), "Jane Doe");
    ASSERT_EQ(newStudents.Get(1).getDepartment(), "HR");
    ASSERT_EQ(newStudents.Get(1).getEmail(), "b@gmail.com");
    ASSERT_EQ(newStudents.Get(1).getUsername(), "janedoe");
    ASSERT_EQ(newStudents.Get(1).getPassword(), "123");
    ASSERT_EQ(newStudents.Get(1).getStudentID(), "2");
    ASSERT_EQ(newStudents.Get(1).getClassID(), "3");
    ASSERT_EQ(newStudents.Get(1).getCourseIDs().Size(), 3);
    ASSERT_EQ(newStudents.Get(1).getCourseIDs().Get(0), "1");
    ASSERT_EQ(newStudents.Get(1).getCourseIDs().Get(1), "6");
    ASSERT_EQ(newStudents.Get(1).getCourseIDs().Get(2), "9");
    ASSERT_EQ(newStudents.Get(1).getGender(), "female");
    ASSERT_EQ(newStudents.Get(1).getDateOfBirth().serialize(), "1-1-2000");
    ASSERT_EQ(newStudents.Get(1).getMajor(), "HR");
    ASSERT_EQ(newStudents.Get(1).getCohort(), "2021");
    ASSERT_EQ(newStudents.Get(1).getSocialID(), "456");
    csvService.deleteFromCSV("2", filePath);
}

TEST(CSVHandlingServiceTest, AppendCSVStudent)
{
    CSVHandlingService<Student> csvService;
    string filePath = "../../data/students.csv";
    LinkedList<Student> students = csvService.importFromCSV(filePath, Student::deserialize);
    LinkedList<string> courseIDs;
    courseIDs.AddToEnd("1");
    courseIDs.AddToEnd("6");
    courseIDs.AddToEnd("9");
    Student student("2", "Jane Doe", "HR", "b@gmail.com", "janedoe", "123", "2", "3", courseIDs, "female", Date(1, 1, 2000), "HR", "2021", "456");
    csvService.appendToCSV(student, filePath);
    LinkedList<Student> newStudents = csvService.importFromCSV(filePath, Student::deserialize);
    ASSERT_EQ(newStudents.Size(), 2);
    ASSERT_EQ(newStudents.Get(1).getID(), "2");
    ASSERT_EQ(newStudents.Get(1).getRole(), "student");
    ASSERT_EQ(newStudents.Get(1).getFullName(), "Jane Doe");
    ASSERT_EQ(newStudents.Get(1).getDepartment(), "HR");
    ASSERT_EQ(newStudents.Get(1).getEmail(), "b@gmail.com");
    ASSERT_EQ(newStudents.Get(1).getUsername(), "janedoe");
    ASSERT_EQ(newStudents.Get(1).getPassword(), "123");
    ASSERT_EQ(newStudents.Get(1).getStudentID(), "2");
    ASSERT_EQ(newStudents.Get(1).getClassID(), "3");
    ASSERT_EQ(newStudents.Get(1).getCourseIDs().Size(), 3);
    ASSERT_EQ(newStudents.Get(1).getCourseIDs().Get(0), "1");
    ASSERT_EQ(newStudents.Get(1).getCourseIDs().Get(1), "6");
    ASSERT_EQ(newStudents.Get(1).getCourseIDs().Get(2), "9");
    ASSERT_EQ(newStudents.Get(1).getGender(), "female");
    ASSERT_EQ(newStudents.Get(1).getDateOfBirth().serialize(), "1-1-2000");
    ASSERT_EQ(newStudents.Get(1).getMajor(), "HR");
    ASSERT_EQ(newStudents.Get(1).getCohort(), "2021");
    ASSERT_EQ(newStudents.Get(1).getSocialID(), "456");
    csvService.deleteFromCSV("2", filePath);
}

TEST(CSVHandlingServiceTest, ReadCSVSemester)
{
    CSVHandlingService<Semester> csvService;
    string filePath = "../../data/semesters.csv";
    LinkedList<Semester> semesters = csvService.importFromCSV(filePath, Semester::deserialize);
    ASSERT_EQ(semesters.Size(), 1);
    ASSERT_EQ(semesters.Get(0).getSemesterID(), "1");
    ASSERT_EQ(semesters.Get(0).getYearID(), "1");
    ASSERT_EQ(semesters.Get(0).getSemesterName(), "Fall");
    ASSERT_EQ(semesters.Get(0).getStartDate().serialize(), "1-1-2016");
    ASSERT_EQ(semesters.Get(0).getEndDate().serialize(), "30-6-2016");
}

TEST(CSVHandlingServiceTest, WriteCSVSemester)
{
    CSVHandlingService<Semester> csvService;
    string filePath = "../../data/semesters.csv";
    LinkedList<Semester> semesters = csvService.importFromCSV(filePath, Semester::deserialize);
    Semester semester("2", "2", "Spring", Date(1, 1, 2017), Date(30, 6, 2017));
    semesters.AddToEnd(semester);
    csvService.exportToCSV(semesters, filePath);
    LinkedList<Semester> newSemesters = csvService.importFromCSV(filePath, Semester::deserialize);
    ASSERT_EQ(newSemesters.Size(), 2);
    ASSERT_EQ(newSemesters.Get(1).getSemesterID(), "2");
    ASSERT_EQ(newSemesters.Get(1).getYearID(), "2");
    ASSERT_EQ(newSemesters.Get(1).getSemesterName(), "Spring");
    ASSERT_EQ(newSemesters.Get(1).getStartDate().serialize(), "1-1-2017");
    ASSERT_EQ(newSemesters.Get(1).getEndDate().serialize(), "30-6-2017");
    csvService.deleteFromCSV("2", filePath);
}

TEST(CSVHandlingServiceTest, AppendCSVSemester)
{
    CSVHandlingService<Semester> csvService;
    string filePath = "../../data/semesters.csv";
    LinkedList<Semester> semesters = csvService.importFromCSV(filePath, Semester::deserialize);
    Semester semester("2", "2", "Spring", Date(1, 1, 2017), Date(30, 6, 2017));
    csvService.appendToCSV(semester, filePath);
    LinkedList<Semester> newSemesters = csvService.importFromCSV(filePath, Semester::deserialize);
    ASSERT_EQ(newSemesters.Size(), 2);
    ASSERT_EQ(newSemesters.Get(1).getSemesterID(), "2");
    ASSERT_EQ(newSemesters.Get(1).getYearID(), "2");
    ASSERT_EQ(newSemesters.Get(1).getSemesterName(), "Spring");
    ASSERT_EQ(newSemesters.Get(1).getStartDate().serialize(), "1-1-2017");
    ASSERT_EQ(newSemesters.Get(1).getEndDate().serialize(), "30-6-2017");
    csvService.deleteFromCSV("2", filePath);
}

TEST(CSVHandlingServiceTest, ReadCSVClass)
{
    CSVHandlingService<Class> csvService;
    string filePath = "../../data/classes.csv";
    LinkedList<Class> classes = csvService.importFromCSV(filePath, Class::deserialize);
    ASSERT_EQ(classes.Size(), 1);
    ASSERT_EQ(classes.Get(0).getClassID(), "1");
    ASSERT_EQ(classes.Get(0).getName(), "Math");
    ASSERT_EQ(classes.Get(0).getListOfStudentIDs().Size(), 3);
    ASSERT_EQ(classes.Get(0).getListOfStudentIDs().Get(0), "1");
    ASSERT_EQ(classes.Get(0).getListOfStudentIDs().Get(1), "2");
    ASSERT_EQ(classes.Get(0).getListOfStudentIDs().Get(2), "3");
}

TEST(CSVHandlingServiceTest, WriteCSVClass)
{
    CSVHandlingService<Class> csvService;
    string filePath = "../../data/classes.csv";
    LinkedList<Class> classes = csvService.importFromCSV(filePath, Class::deserialize);
    LinkedList<string> studentIDs;
    studentIDs.AddToEnd("1");
    studentIDs.AddToEnd("2");
    studentIDs.AddToEnd("4");
    Class newClass("2", "Physics", studentIDs);
    classes.AddToEnd(newClass);
    csvService.exportToCSV(classes, filePath);
    LinkedList<Class> newClasses = csvService.importFromCSV(filePath, Class::deserialize);
    ASSERT_EQ(newClasses.Size(), 2);
    ASSERT_EQ(newClasses.Get(1).getClassID(), "2");
    ASSERT_EQ(newClasses.Get(1).getName(), "Physics");
    ASSERT_EQ(newClasses.Get(1).getListOfStudentIDs().Size(), 3);
    ASSERT_EQ(newClasses.Get(1).getListOfStudentIDs().Get(0), "1");
    ASSERT_EQ(newClasses.Get(1).getListOfStudentIDs().Get(1), "2");
    ASSERT_EQ(newClasses.Get(1).getListOfStudentIDs().Get(2), "4");
    csvService.deleteFromCSV("2", filePath);
}

TEST(CSVHandlingServiceTest, AppendCSVClass)
{
    CSVHandlingService<Class> csvService;
    string filePath = "../../data/classes.csv";
    LinkedList<Class> classes = csvService.importFromCSV(filePath, Class::deserialize);
    LinkedList<string> studentIDs;
    studentIDs.AddToEnd("1");
    studentIDs.AddToEnd("2");
    studentIDs.AddToEnd("5");
    Class newClass("2", "Physics", studentIDs);
    csvService.appendToCSV(newClass, filePath);
    LinkedList<Class> newClasses = csvService.importFromCSV(filePath, Class::deserialize);
    ASSERT_EQ(newClasses.Size(), 2);
    ASSERT_EQ(newClasses.Get(1).getClassID(), "2");
    ASSERT_EQ(newClasses.Get(1).getName(), "Physics");
    ASSERT_EQ(newClasses.Get(1).getListOfStudentIDs().Size(), 3);
    ASSERT_EQ(newClasses.Get(1).getListOfStudentIDs().Get(0), "1");
    ASSERT_EQ(newClasses.Get(1).getListOfStudentIDs().Get(1), "2");
    ASSERT_EQ(newClasses.Get(1).getListOfStudentIDs().Get(2), "5");
    csvService.deleteFromCSV("2", filePath);
}

TEST(CSVHandlingServiceTest, ReadCSVCourse)
{
    CSVHandlingService<Course> csvService;
    string filePath = "../../data/courses.csv";
    LinkedList<Course> courses = csvService.importFromCSV(filePath, Course::deserialize);
    ASSERT_EQ(courses.Size(), 1);
    ASSERT_EQ(courses.Get(0).getCourseID(), "10CSE101");
    ASSERT_EQ(courses.Get(0).getCourseName(), "Introduction to Computer Science");
    ASSERT_EQ(courses.Get(0).getSemesterID(), "1");
    ASSERT_EQ(courses.Get(0).getClassID(), "10");
    ASSERT_EQ(courses.Get(0).getTeacherNames().Size(), 1);
    ASSERT_EQ(courses.Get(0).getTeacherNames().Get(0), "Mr. A");
    ASSERT_EQ(courses.Get(0).getNumberOfCredits(), 3);
    ASSERT_EQ(courses.Get(0).getCapacity(), 30);
    ASSERT_EQ(courses.Get(0).getDayOfWeek(), "Monday");
    ASSERT_EQ(courses.Get(0).getSessionTime(), "10:00-12:00");
    ASSERT_EQ(courses.Get(0).getEnrolledStudentsList().Size(), 4);
    ASSERT_EQ(courses.Get(0).getEnrolledStudentsList().Get(0), "101");
    ASSERT_EQ(courses.Get(0).getEnrolledStudentsList().Get(1), "105");
    ASSERT_EQ(courses.Get(0).getEnrolledStudentsList().Get(2), "106");
    ASSERT_EQ(courses.Get(0).getEnrolledStudentsList().Get(3), "107");
}

TEST(CSVHandlingServiceTest, WriteCSVCourse)
{
    CSVHandlingService<Course> csvService;
    string filePath = "../../data/courses.csv";
    LinkedList<Course> courses = csvService.importFromCSV(filePath, Course::deserialize);
    LinkedList<string> teacherNames;
    teacherNames.AddToEnd("Mr. B");
    LinkedList<string> enrolledStudentsList;
    enrolledStudentsList.AddToEnd("101");
    enrolledStudentsList.AddToEnd("105");
    enrolledStudentsList.AddToEnd("106");
    enrolledStudentsList.AddToEnd("107");
    Course course("10CSE102", "Data Structures", "2", "11", teacherNames, 4, 40, "Tuesday", "10:00-12:00", enrolledStudentsList);
    courses.AddToEnd(course);
    csvService.exportToCSV(courses, filePath);
    LinkedList<Course> newCourses = csvService.importFromCSV(filePath, Course::deserialize);
    ASSERT_EQ(newCourses.Size(), 2);
    ASSERT_EQ(newCourses.Get(1).getCourseID(), "10CSE102");
    ASSERT_EQ(newCourses.Get(1).getCourseName(), "Data Structures");
    ASSERT_EQ(newCourses.Get(1).getSemesterID(), "2");
    ASSERT_EQ(newCourses.Get(1).getClassID(), "11");
    ASSERT_EQ(newCourses.Get(1).getTeacherNames().Size(), 1);
    ASSERT_EQ(newCourses.Get(1).getTeacherNames().Get(0), "Mr. B");
    ASSERT_EQ(newCourses.Get(1).getNumberOfCredits(), 4);
    ASSERT_EQ(newCourses.Get(1).getCapacity(), 40);
    ASSERT_EQ(newCourses.Get(1).getDayOfWeek(), "Tuesday");
    ASSERT_EQ(newCourses.Get(1).getSessionTime(), "10:00-12:00");
    ASSERT_EQ(newCourses.Get(1).getEnrolledStudentsList().Size(), 4);
    ASSERT_EQ(newCourses.Get(1).getEnrolledStudentsList().Get(0), "101");
    ASSERT_EQ(newCourses.Get(1).getEnrolledStudentsList().Get(1), "105");
    ASSERT_EQ(newCourses.Get(1).getEnrolledStudentsList().Get(2), "106");
    ASSERT_EQ(newCourses.Get(1).getEnrolledStudentsList().Get(3), "107");
    csvService.deleteFromCSV("10CSE102", filePath);
}

TEST(CSVHandlingServiceTest, AppendCSVCourse)
{
    CSVHandlingService<Course> csvService;
    string filePath = "../../data/courses.csv";
    LinkedList<Course> courses = csvService.importFromCSV(filePath, Course::deserialize);
    LinkedList<string> teacherNames;
    teacherNames.AddToEnd("Mr. B");
    LinkedList<string> enrolledStudentsList;
    enrolledStudentsList.AddToEnd("101");
    enrolledStudentsList.AddToEnd("105");
    enrolledStudentsList.AddToEnd("106");
    enrolledStudentsList.AddToEnd("107");
    Course course("10CSE102", "Data Structures", "2", "11", teacherNames, 4, 40, "Tuesday", "10:00-12:00", enrolledStudentsList);
    csvService.appendToCSV(course, filePath);
    LinkedList<Course> newCourses = csvService.importFromCSV(filePath, Course::deserialize);
    ASSERT_EQ(newCourses.Size(), 2);
    ASSERT_EQ(newCourses.Get(1).getCourseID(), "10CSE102");
    ASSERT_EQ(newCourses.Get(1).getCourseName(), "Data Structures");
    ASSERT_EQ(newCourses.Get(1).getSemesterID(), "2");
    ASSERT_EQ(newCourses.Get(1).getClassID(), "11");
    ASSERT_EQ(newCourses.Get(1).getTeacherNames().Size(), 1);
    ASSERT_EQ(newCourses.Get(1).getTeacherNames().Get(0), "Mr. B");
    ASSERT_EQ(newCourses.Get(1).getNumberOfCredits(), 4);
    ASSERT_EQ(newCourses.Get(1).getCapacity(), 40);
    ASSERT_EQ(newCourses.Get(1).getDayOfWeek(), "Tuesday");
    ASSERT_EQ(newCourses.Get(1).getSessionTime(), "10:00-12:00");
    ASSERT_EQ(newCourses.Get(1).getEnrolledStudentsList().Size(), 4);
    ASSERT_EQ(newCourses.Get(1).getEnrolledStudentsList().Get(0), "101");
    ASSERT_EQ(newCourses.Get(1).getEnrolledStudentsList().Get(1), "105");
    ASSERT_EQ(newCourses.Get(1).getEnrolledStudentsList().Get(2), "106");
    ASSERT_EQ(newCourses.Get(1).getEnrolledStudentsList().Get(3), "107");
    csvService.deleteFromCSV("10CSE102", filePath);
}

TEST(CSVHandlingServiceTest, ReadCSVScoreboard)
{
    CSVHandlingService<Scoreboard> csvService;
    string filePath = "../../data/scoreboards.csv";
    LinkedList<Scoreboard> scoreboards = csvService.importFromCSV(filePath, Scoreboard::deserialize);
    ASSERT_EQ(scoreboards.Size(), 1);
    ASSERT_EQ(scoreboards.Get(0).getCourseID(), "10CSE101");
    map<string, DetailedScore> scores = scoreboards.Get(0).getScores();
    ASSERT_EQ(scores.size(), 2);
    EXPECT_NEAR(scores["1"].getOtherMark(), 9.0, 0.001);
    EXPECT_NEAR(scores["1"].getMidtermMark(), 9.0, 0.001);
    EXPECT_NEAR(scores["1"].getFinalMark(), 9.0, 0.001);
    EXPECT_NEAR(scores["1"].geTotalMark(), 9.8, 0.001);
    EXPECT_NEAR(scores["2"].getOtherMark(), 8.0, 0.001);
    EXPECT_NEAR(scores["2"].getMidtermMark(), 8.0, 0.001);
    EXPECT_NEAR(scores["2"].getFinalMark(), 8.0, 0.001);
    EXPECT_NEAR(scores["2"].geTotalMark(), 8.8, 0.001);
}

TEST(CSVHandlingServiceTest, WriteCSVScoreboard)
{
    CSVHandlingService<Scoreboard> csvService;
    string filePath = "../../data/scoreboards.csv";
    LinkedList<Scoreboard> scoreboards = csvService.importFromCSV(filePath, Scoreboard::deserialize);
    map<string, DetailedScore> scores;
    scores["1"] = DetailedScore(9.0, 9.0, 9.0, 9.8);
    scores["2"] = DetailedScore(8.0, 8.0, 8.0, 8.8);
    Scoreboard scoreboard("10CSE102", scores);
    scoreboards.AddToEnd(scoreboard);
    csvService.exportToCSV(scoreboards, filePath);
    LinkedList<Scoreboard> newScoreboards = csvService.importFromCSV(filePath, Scoreboard::deserialize);
    ASSERT_EQ(newScoreboards.Size(), 2);
    ASSERT_EQ(newScoreboards.Get(1).getCourseID(), "10CSE102");
    map<string, DetailedScore> newScores = newScoreboards.Get(1).getScores();
    ASSERT_EQ(newScores.size(), 2);
    EXPECT_NEAR(newScores["1"].getOtherMark(), 9.0, 0.001);
    EXPECT_NEAR(newScores["1"].getMidtermMark(), 9.0, 0.001);
    EXPECT_NEAR(newScores["1"].getFinalMark(), 9.0, 0.001);
    EXPECT_NEAR(newScores["1"].geTotalMark(), 9.8, 0.001);
    EXPECT_NEAR(newScores["2"].getOtherMark(), 8.0, 0.001);
    EXPECT_NEAR(newScores["2"].getMidtermMark(), 8.0, 0.001);
    EXPECT_NEAR(newScores["2"].getFinalMark(), 8.0, 0.001);
    EXPECT_NEAR(newScores["2"].geTotalMark(), 8.8, 0.001);
    csvService.deleteFromCSV("10CSE102", filePath);
}

TEST(CSVHandlingServiceTest, AppendCSVScoreboard)
{
    CSVHandlingService<Scoreboard> csvService;
    string filePath = "../../data/scoreboards.csv";
    LinkedList<Scoreboard> scoreboards = csvService.importFromCSV(filePath, Scoreboard::deserialize);
    map<string, DetailedScore> scores;
    scores["1"] = DetailedScore(9.0, 9.0, 9.0, 9.8);
    scores["2"] = DetailedScore(8.0, 8.0, 8.0, 8.8);
    Scoreboard scoreboard("10CSE102", scores);
    csvService.appendToCSV(scoreboard, filePath);
    LinkedList<Scoreboard> newScoreboards = csvService.importFromCSV(filePath, Scoreboard::deserialize);
    ASSERT_EQ(newScoreboards.Size(), 2);
    ASSERT_EQ(newScoreboards.Get(1).getCourseID(), "10CSE102");
    map<string, DetailedScore> newScores = newScoreboards.Get(1).getScores();
    ASSERT_EQ(newScores.size(), 2);
    EXPECT_NEAR(newScores["1"].getOtherMark(), 9.0, 0.001);
    EXPECT_NEAR(newScores["1"].getMidtermMark(), 9.0, 0.001);
    EXPECT_NEAR(newScores["1"].getFinalMark(), 9.0, 0.001);
    EXPECT_NEAR(newScores["1"].geTotalMark(), 9.8, 0.001);
    EXPECT_NEAR(newScores["2"].getOtherMark(), 8.0, 0.001);
    EXPECT_NEAR(newScores["2"].getMidtermMark(), 8.0, 0.001);
    EXPECT_NEAR(newScores["2"].getFinalMark(), 8.0, 0.001);
    EXPECT_NEAR(newScores["2"].geTotalMark(), 8.8, 0.001);
    csvService.deleteFromCSV("10CSE102", filePath);
}

TEST(CSVHandlingServiceTest, ReadCSVYear)
{
    CSVHandlingService<SchoolYear> csvService;
    string filePath = "../../data/school_years.csv";
    LinkedList<SchoolYear> years = csvService.importFromCSV(filePath, SchoolYear::deserialize);
    ASSERT_EQ(years.Size(), 1);
    ASSERT_EQ(years.Get(0).getYearID(), "2018");
    ASSERT_EQ(years.Get(0).getStartDate().serialize(), "1-1-2018");
    ASSERT_EQ(years.Get(0).getEndDate().serialize(), "30-6-2018");
    ASSERT_EQ(years.Get(0).getSemesterIDs().Size(), 2);
    ASSERT_EQ(years.Get(0).getSemesterIDs().Get(0), "1");
    ASSERT_EQ(years.Get(0).getSemesterIDs().Get(1), "2");
}

TEST(CSVHandlingServiceTest, WriteCSVYear)
{
    CSVHandlingService<SchoolYear> csvService;
    string filePath = "../../data/school_years.csv";
    LinkedList<SchoolYear> years = csvService.importFromCSV(filePath, SchoolYear::deserialize);
    LinkedList<string> semesterIDs;
    semesterIDs.AddToEnd("1");
    semesterIDs.AddToEnd("2");
    SchoolYear year("2019", Date(1, 1, 2019), Date(30, 6, 2019), semesterIDs);
    years.AddToEnd(year);
    csvService.exportToCSV(years, filePath);
    LinkedList<SchoolYear> newYears = csvService.importFromCSV(filePath, SchoolYear::deserialize);
    ASSERT_EQ(newYears.Size(), 2);
    ASSERT_EQ(newYears.Get(1).getYearID(), "2019");
    ASSERT_EQ(newYears.Get(1).getStartDate().serialize(), "1-1-2019");
    ASSERT_EQ(newYears.Get(1).getEndDate().serialize(), "30-6-2019");
    ASSERT_EQ(newYears.Get(1).getSemesterIDs().Size(), 2);
    ASSERT_EQ(newYears.Get(1).getSemesterIDs().Get(0), "1");
    ASSERT_EQ(newYears.Get(1).getSemesterIDs().Get(1), "2");
    csvService.deleteFromCSV("2019", filePath);
}

TEST(CSVHandlingServiceTest, AppendCSVYear)
{
    CSVHandlingService<SchoolYear> csvService;
    string filePath = "../../data/school_years.csv";
    LinkedList<SchoolYear> years = csvService.importFromCSV(filePath, SchoolYear::deserialize);
    LinkedList<string> semesterIDs;
    semesterIDs.AddToEnd("1");
    semesterIDs.AddToEnd("2");
    SchoolYear year("2019", Date(1, 1, 2019), Date(30, 6, 2019), semesterIDs);
    csvService.appendToCSV(year, filePath);
    LinkedList<SchoolYear> newYears = csvService.importFromCSV(filePath, SchoolYear::deserialize);
    ASSERT_EQ(newYears.Size(), 2);
    ASSERT_EQ(newYears.Get(1).getYearID(), "2019");
    ASSERT_EQ(newYears.Get(1).getStartDate().serialize(), "1-1-2019");
    ASSERT_EQ(newYears.Get(1).getEndDate().serialize(), "30-6-2019");
    ASSERT_EQ(newYears.Get(1).getSemesterIDs().Size(), 2);
    ASSERT_EQ(newYears.Get(1).getSemesterIDs().Get(0), "1");
    ASSERT_EQ(newYears.Get(1).getSemesterIDs().Get(1), "2");
    csvService.deleteFromCSV("2019", filePath);
}

TEST(CSVHandlingServiceTest, ReadCSVAcademicStaff)
{
    CSVHandlingService<AcademicStaff> csvService;
    string filePath = "../../data/academic_staffs.csv";
    LinkedList<AcademicStaff> academicStaffs = csvService.importFromCSV(filePath, AcademicStaff::deserialize);
    ASSERT_EQ(academicStaffs.Size(), 1);
    ASSERT_EQ(academicStaffs.Get(0).getID(), "1");
    ASSERT_EQ(academicStaffs.Get(0).getFullName(), "John Doe");
    ASSERT_EQ(academicStaffs.Get(0).getDepartment(), "IT");
    ASSERT_EQ(academicStaffs.Get(0).getEmail(), "a@gmail.com");
    ASSERT_EQ(academicStaffs.Get(0).getUsername(), "johndoe");
    ASSERT_EQ(academicStaffs.Get(0).getPassword(), "123456");
    ASSERT_EQ(academicStaffs.Get(0).getStaffID(), "1");
}

TEST(CSVHandlingServiceTest, WriteCSVAcademicStaff)
{
    CSVHandlingService<AcademicStaff> csvService;
    string filePath = "../../data/academic_staffs.csv";
    LinkedList<AcademicStaff> academicStaffs = csvService.importFromCSV(filePath, AcademicStaff::deserialize);
    AcademicStaff academicStaff("2", "Jane Doe", "HR", "bubu@gmail.com", "janedoe", "123456", "2");
    academicStaffs.AddToEnd(academicStaff);
    csvService.exportToCSV(academicStaffs, filePath);
    LinkedList<AcademicStaff> newAcademicStaffs = csvService.importFromCSV(filePath, AcademicStaff::deserialize);
    ASSERT_EQ(newAcademicStaffs.Size(), 2);
    ASSERT_EQ(newAcademicStaffs.Get(1).getID(), "2");
    ASSERT_EQ(newAcademicStaffs.Get(1).getFullName(), "Jane Doe");
    ASSERT_EQ(newAcademicStaffs.Get(1).getDepartment(), "HR");
    ASSERT_EQ(newAcademicStaffs.Get(1).getEmail(), "bubu@gmail.com");
    ASSERT_EQ(newAcademicStaffs.Get(1).getUsername(), "janedoe");
    ASSERT_EQ(newAcademicStaffs.Get(1).getPassword(), "123456");
    ASSERT_EQ(newAcademicStaffs.Get(1).getStaffID(), "2");
    csvService.deleteFromCSV("2", filePath);
}

TEST(CSVHandlingServiceTest, AppendCSVAcademicStaff)
{
    CSVHandlingService<AcademicStaff> csvService;
    string filePath = "../../data/academic_staffs.csv";
    LinkedList<AcademicStaff> academicStaffs = csvService.importFromCSV(filePath, AcademicStaff::deserialize);
    AcademicStaff academicStaff("2", "Jane Doe", "HR", "bubu@gmail.com", "janedoe", "123456", "2");
    csvService.appendToCSV(academicStaff, filePath);
    LinkedList<AcademicStaff> newAcademicStaffs = csvService.importFromCSV(filePath, AcademicStaff::deserialize);
    ASSERT_EQ(newAcademicStaffs.Size(), 2);
    ASSERT_EQ(newAcademicStaffs.Get(1).getID(), "2");
    ASSERT_EQ(newAcademicStaffs.Get(1).getFullName(), "Jane Doe");
    ASSERT_EQ(newAcademicStaffs.Get(1).getDepartment(), "HR");
    ASSERT_EQ(newAcademicStaffs.Get(1).getEmail(), "bubu@gmail.com");
    ASSERT_EQ(newAcademicStaffs.Get(1).getUsername(), "janedoe");
    ASSERT_EQ(newAcademicStaffs.Get(1).getPassword(), "123456");
    ASSERT_EQ(newAcademicStaffs.Get(1).getStaffID(), "2");
    csvService.deleteFromCSV("2", filePath);
}