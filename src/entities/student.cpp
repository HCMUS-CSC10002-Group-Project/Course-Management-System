#include "student.h"
#include "../utils/StringUtils.h"
#include "../utils/UUID.h"
#include <iostream>

Student::Student(string fullName, string department, string email, string username, string password, string classID, string gender, Date dateOfBirth, string major, string cohort, string socialID)
    : User("student", fullName, department, email, username, password), class_ID(classID), gender(gender), date_of_birth(dateOfBirth), major(major), cohort(cohort), social_ID(socialID)
{
    this->student_ID = UUIDGenerator::generate();
}

Student::Student(string ID, string fullName, string department, string email, string username, string password, string studentID, string classID, LinkedList<string> courseIDs, string gender, Date dateOfBirth, string major, string cohort, string socialID)
    : User(ID, "student", fullName, department, email, username, password), student_ID(studentID), class_ID(classID), course_IDs(courseIDs), gender(gender), date_of_birth(dateOfBirth), major(major), cohort(cohort), social_ID(socialID)
{
}

string Student::getStudentID()
{
    return this->student_ID;
}

string Student::getClassID()
{
    return this->class_ID;
}

bool Student::setClassID(string newClassID)
{
    if (newClassID.empty())
    {
        return false;
    }
    this->class_ID = newClassID;
    return true;
}

bool Student::addCourse(string newCourseID)
{
    if (this->course_IDs.Find(newCourseID))
    {
        return false;
    }
    this->course_IDs.AddToEnd(newCourseID);
    return true;
}

bool Student::removeCourse(string courseID)
{
    if (!this->course_IDs.Find(courseID))
    {
        return false;
    }
    this->course_IDs.Remove(courseID);
    return true;
}

LinkedList<string> Student::getCourseIDs()
{
    return this->course_IDs;
}

string Student::getGender()
{
    return this->gender;
}

bool Student::setGender(string newGender)
{
    if (newGender.empty())
    {
        return false;
    }
    this->gender = newGender;
    return true;
}

Date Student::getDateOfBirth()
{
    return this->date_of_birth;
}

bool Student::setDateOfBirth(Date newDateOfBirth)
{
    if (!newDateOfBirth.isValid())
    {
        return false;
    }
    this->date_of_birth = newDateOfBirth;
    return true;
}

string Student::getMajor()
{
    return this->major;
}

bool Student::setMajor(string newMajor)
{
    if (newMajor.empty())
    {
        return false;
    }
    this->major = newMajor;
    return true;
}

string Student::getCohort()
{
    return this->cohort;
}

bool Student::setCohort(string newCohort)
{
    if (newCohort.empty())
    {
        return false;
    }
    this->cohort = newCohort;
    return true;
}

string Student::getSocialID()
{
    return this->social_ID;
}

bool Student::setSocialID(string newSocialID)
{
    if (newSocialID.empty())
    {
        return false;
    }
    this->social_ID = newSocialID;
    return true;
}

string Student::serialize()
{
    string serialized = this->getID() + "," + this->getFullName() + "," + this->getDepartment() + "," + this->getEmail() + "," + this->getUsername() + "," + this->getPassword() + "," + this->student_ID + "," + this->class_ID + ",";
    for (int i = 0; i < this->course_IDs.Size(); i++)
    {
        serialized += this->course_IDs.Get(i);
        if (i < this->course_IDs.Size() - 1)
        {
            serialized += ";";
        }
    }
    serialized += "," + this->getGender() + "," + this->date_of_birth.serialize() + "," + this->major + "," + this->cohort + "," + this->social_ID;
    return serialized;
}

Student Student::deserialize(const string &serialized)
{
    DynamicArray<string> data = split(serialized, ',');
    string curID = data.Get(0);
    string curFullName = data.Get(1);
    string curDepartment = data.Get(2);
    string curEmail = data.Get(3);
    string curUsername = data.Get(4);
    string curPassword = data.Get(5);
    string curStudentID = data.Get(6);
    string curClassID = data.Get(7);
    LinkedList<string> curCourseIDs;
    DynamicArray<string> courseIDs = split(data.Get(8), ';');
    for (int i = 0; i < courseIDs.Size(); i++)
    {
        curCourseIDs.AddToEnd(courseIDs.Get(i));
    }
    string curGender = data.Get(9);
    Date curDateOfBirth = Date::deserialize(data.Get(10));
    string curMajor = data.Get(11);
    string curCohort = data.Get(12);
    string curSocialID = data.Get(13);
    return Student(curID, curFullName, curDepartment, curEmail, curUsername, curPassword, curStudentID, curClassID, curCourseIDs, curGender, curDateOfBirth, curMajor, curCohort, curSocialID);
}

string Student::getHeader()
{
    return "ID,Full Name,Department,Email,Username,Password,Student ID,Class ID,Course IDs,Gender,Date of Birth,Major,Cohort,Social ID";
}
