#include <string>
using std::string;
class Semester
{
    private:
        string semester_ID;
        string year_ID;
        int semester_number;
        Date start_date;
        Date end_Date;
    public:
        bool addCourse();
};
