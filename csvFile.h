#ifndef FILECSV_H
#define FILECSV_H
#include <string>
#include <fstream>

class CsvFile
{
public:
    CsvFile(std::string name);
    ~CsvFile();

private:
    std::fstream file;

};

#endif // FILECSV_H
