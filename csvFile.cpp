#include "csvFile.h"
#include <fstream>
#include <iostream>

CsvFile::CsvFile(std::string name)
{
    if(name.substr(name.size()-4, 4) != ".csv")
    {
         name += ".csv";
    }


    if(!file)
    {
        if (name.find("/") != name.size())
        {
            std::cerr << "\nОшибка: невозможно создать файл \"" << name << "\"\n\n";
        }
        else
        {
            std::cerr << "\nОшибка: невозможно создать файл по указанному пути \"" << name << "\"\n\n";
        }
        return;
    }
}

CsvFile::~CsvFile()
{

}
