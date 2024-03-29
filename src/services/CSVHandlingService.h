#ifndef CSV_HANDLING_SERVICE_H
#define CSV_HANDLING_SERVICE_H

#include "../data_structures/LinkedList.h"
#include <string>
#include <functional>

template <typename T>
class CSVHandlingService
{
public:
    static bool exportToCSV(const LinkedList<T> &data, const std::string &filePath);
    static LinkedList<T> importFromCSV(const std::string &filePath, std::function<T(const std::string &)> deserializer);
    static std::string generateCSVFromData(const LinkedList<T> &data);
    static LinkedList<T> parseCSVToData(const std::string &CSVString, std::function<T(const std::string &)> deserializer);
    static bool appendToCSV(T &object, const std::string &filePath);
    static bool deleteFromCSV(const std::string &ID, const std::string &filePath);
};

#include "CSVHandlingServiceImpl.h" // Implementation of template class

#endif // CSV_HANDLING_SERVICE_H
