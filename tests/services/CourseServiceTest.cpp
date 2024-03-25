#include <gtest/gtest.h>
#include "courseService.h"

class CourseServiceTest : public ::testing::Test
{
protected:
    CourseService courseService;
};

TEST_F(CourseServiceTest, AddCourse)
{
    Course course = Course("2021-2022-1", "CS162", 4, 50, "Monday", "7:30-9:30");
    ASSERT_TRUE(courseService.addCourse(course));
    ASSERT_TRUE(courseService.deleteCourse(course));
}

TEST_F(CourseServiceTest, UpdateCourse)
{
    Course course = Course("2021-2022-1", "CS162", 4, 50, "Monday", "7:30-9:30");
    ASSERT_TRUE(courseService.addCourse(course));
    Course newCourse = Course("2021-2022-1", "CS162", 4, 50, "Monday", "7:30-9:30");
    ASSERT_TRUE(courseService.updateCourse(course.getCourseID(), newCourse));
    ASSERT_TRUE(courseService.deleteCourse(newCourse));
}

TEST_F(CourseServiceTest, viewCourses)
{
    Course course = Course("2021-2022-1", "CS162", 4, 50, "Monday", "7:30-9:30");
    ASSERT_TRUE(courseService.addCourse(course));
    LinkedList<Course> courses = courseService.viewCourses();
    ASSERT_TRUE(courses.Size() == 1);
    ASSERT_FALSE(courseService.addCourse(course));
    ASSERT_EQ(courses.Get(0).getCourseID(), course.getCourseID());
    ASSERT_EQ(courses.Size(), 1);
    ASSERT_TRUE(courseService.deleteCourse(course));
}