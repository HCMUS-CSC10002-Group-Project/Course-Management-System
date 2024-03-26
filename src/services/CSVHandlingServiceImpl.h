#ifndef CSV_HANDLING_SERVICE_IMPL_H
#define CSV_HANDLING_SERVICE_IMPL_H
#include <fstream>
#include <sstream>
#include "CSVHandlingService.h"
#include <iostream>

template <typename T>
bool CSVHandlingService<T>::exportToCSV(const LinkedList<T> &data, const std::string &filePath)
{
    std::ofstream file(filePath);
    if (!file.is_open())
    {
        return false;
    }

    file << generateCSVFromData(data);
    file.close();
    return true;
}

template <typename T>
LinkedList<T> CSVHandlingService<T>::importFromCSV(const std::string &filePath, std::function<T(const std::string &)> deserializer)
{
    std::ifstream file(filePath);
    std::stringstream buffer;
    buffer << file.rdbuf();
    return parseCSVToData(buffer.str(), deserializer);
}

template <typename T>
std::string CSVHandlingService<T>::generateCSVFromData(const LinkedList<T> &data)
{
    std::string CSVString;
    CSVString += data.Get(0).getHeader() + "\n";
    for (int i = 0; i < data.Size(); i++)
    {
        CSVString += data.Get(i).serialize() + "\n";
    }
    return CSVString;
}

template <typename T>
LinkedList<T> CSVHandlingService<T>::parseCSVToData(const std::string &CSVString, std::function<T(const std::string &)> deserializer)
{
    LinkedList<T> data;
    std::stringstream stream(CSVString);
    std::string line;
    std::getline(stream, line); // Skip the header line
    while (std::getline(stream, line))
    {
        data.AddToEnd(deserializer(line));
    }
    return data;
}

template <typename T>
bool CSVHandlingService<T>::appendToCSV(T &object, const std::string &filePath)
{
    std::ofstream file(filePath, std::ios_base::app);
    if (!file.is_open())
    {
        return false;
    }

    file << object.serialize() << "\n";
    file.close();
    return true;
}

template <typename T>
bool CSVHandlingService<T>::deleteFromCSV(const std::string &ID, const std::string &filePath)
{
    std::ifstream file(filePath);
    std::ofstream tempFile("temp.csv");
    if (!file.is_open() || !tempFile.is_open())
    {
        return false;
    }

    std::string line;
    std::getline(file, line);
    tempFile << line << "\n";
    while (std::getline(file, line))
    {
        std::stringstream stream(line);
        std::string currentID;
        std::getline(stream, currentID, ',');
        if (currentID != ID)
        {
            tempFile << line << "\n";
        }
    }

    file.close();
    tempFile.close();
    remove(filePath.c_str());
    rename("temp.csv", filePath.c_str());
    return true;
}

#endif // CSV_HANDLING_SERVICE_IMPL_H
