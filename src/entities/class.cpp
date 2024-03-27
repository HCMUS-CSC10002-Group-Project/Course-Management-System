#include "class.h"
#include "../utils/StringUtils.h"
#include "../utils/UUID.h"

Class::Class(string name, LinkedList<string> student_IDs)
{
    class_ID = UUIDGenerator::generate();
    this->name = name;
    this->student_IDs = student_IDs;
}

Class::Class(string class_ID, string name, LinkedList<string> student_IDs)
{
    this->class_ID = class_ID;
    this->name = name;
    this->student_IDs = student_IDs;
}

string Class::getClassID()
{
    return class_ID;
}

string Class::getName()
{
    return name;
}

LinkedList<string> Class::getListOfStudentIDs()
{
    return student_IDs;
}

bool Class::setName(string name)
{
    this->name = name;
    return true;
}

string Class::serialize()
{
    string serialized = class_ID + "," + name + ',';
    for (int i = 0; i < student_IDs.Size(); i++)
    {
        serialized += student_IDs.Get(i);
        if (i < student_IDs.Size() - 1)
        {
            serialized += ';';
        }
    }
    return serialized;
}

Class Class::deserialize(const string &serialized)
{
    DynamicArray<string> data = split(serialized, ',');
    string class_ID = data.Get(0);
    string name = data.Get(1);
    LinkedList<string> student_IDs;
    DynamicArray<string> student_IDs_data = split(data.Get(2), ';');
    for (int i = 0; i < student_IDs_data.Size(); i++)
    {
        student_IDs.AddToEnd(student_IDs_data.Get(i));
    }
    return Class(class_ID, name, student_IDs);
}

string Class::getHeader()
{
    return "Class ID,Name,Student IDs";
}