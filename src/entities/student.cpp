#include "student.h"

Student::Student(string fullName, string department, string email, string username, string password, string classID, string gender, Date dateOfBirth, string major, int cohort, string socialID)
    : User("student", fullName, department, email, username, password),                                                // Example role is "student", and splitting fullName
      class_ID(classID), gender(gender), date_of_birth(dateOfBirth), major(major), cohort(cohort), social_ID(socialID) // Initialize Student-specific members
{
    // Constructor body can be empty if no additional initialization is required
    // If you have logic to split the fullName into first and last names, it would go here
}