#ifndef CSV_HANDLING_SERVICE_H
#define CSV_HANDLING_SERVICE_H

#include "../data_structures/LinkedList.h"

template <typename T>
class CSVHandlingService
{
    public:
    bool exportToCSV(LinkedList<T> data, string filePath);
    LinkedList<T> importFromCSV(string filePath)
    string generateCSVFromData(LinkedList<T> data);
    LinkedList<T> parseCSVToData(string CSVString);
};

#endif //CSV_HANDLING_SERVICE_H
