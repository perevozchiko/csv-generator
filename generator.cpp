#include "generator.h"
#include <random>
#include <ctime>
#include <iostream>

Generator::Generator(int _numColumns, int _maxLengthString) :
    numColumns(_numColumns),
    maxLengthString(_maxLengthString)
{
    generateHeader();
}

Generator::~Generator()
{

}

std::string Generator::generateRow()
{
    if (header.size() == 0)
    {
        std::cerr << "\nОшибка: нет заголовков\n\n";
    }

    std::string row = "";

    for (size_t i = 0; i < header.size(); i++)
    {
        Column col = header[i];
        switch (col.typeName)
        {
        case Type::String:
        {
            int length = randomInt(1, maxIntLength);
            row += generateRandomString(Cell::simple, length);
            break;
        }
        case Type::Integer:
        {
            row += std::to_string(randomInt(0, maxIntLength));
            break;
        }
        case Type::Float:
        {
            row += std::to_string(randomFloat(0, maxFloatLength));
            break;
        }
        case Type::Date:
        {
            row += getRandomData();
        }
        }
        if (i != (header.size()-1))
        {
            row += delimeter;
        }
        else
        {
            row += endLine;
        }
    }
    return  row;
}

std::string Generator::getHeader()
{
    std::string outputData;
    for(size_t i = 0; i < header.size(); i++)
    {
        outputData = outputData +
                header[i].columnName +
                whiteSpace +
                getTypeAsString(header[i].typeName);
        if (i != header.size()-1)
        {
            outputData += delimeter;
        }
        else
        {
            outputData += endLine;
        }
    }
    return  outputData;
}

Type Generator::getRandomType()
{
    int randomNum = randomInt(1,4);
    if (1 <= randomNum && randomNum <= 4)
    {
        randomNum = 0;
    }

    return static_cast<Type>(randomNum);
}

int Generator::randomInt(int min, int max)
{
    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    std::uniform_int_distribution<int> uni(min,max); // guaranteed unbiased

    return uni(rng);
}

float Generator::randomFloat(float min, float max)
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<float> dis(min, max);
    return dis(gen);
}

std::string Generator::getRandomData()
{
    bool isLeapYear = false;
    int year = randomInt(1, 9999);
    int month = randomInt(1, 12);
    int day = 0;
    if (month == 1 or month == 3 or month == 5 or month == 7 or month == 8 or month == 10 or month == 12)
    {
        day = randomInt(1, 31);
    }
    else if (month == 2)
    {
        if (year > 1582)
        {
            if(year%100 == 0)
            {
                isLeapYear = (year%400 == 0);
            }
            else
            {
                isLeapYear = (year%4 == 0);
            }

        }

        if (isLeapYear)
        {
            day = randomInt(1, 29);
        }
        else
        {
            day = randomInt(1, 28);
        }
    }
    else
    {
        day = randomInt(1, 30);
    }

    std::string dayStr;
    std::string monthStr;
    std::string yearStr;
    dayStr = std::to_string(day);
    monthStr = std::to_string(month);
    yearStr = std::to_string(year);
    if (day < 10)
    {
        dayStr = "0" + dayStr;
    }
    if (month < 10)
    {
        monthStr = "0" + monthStr;
    }
    unsigned long numYearSym = yearStr.size();
    while (numYearSym--)
    {
        yearStr = "0" + yearStr;
    }
    return dayStr + pointer + monthStr + pointer + yearStr;

}

void Generator::generateHeader()
{
    Column column;
    for (int i = 0; i < numColumns; i++)
    {
        int lengthString = randomInt(1, maxLengthString);

        column.columnName = generateRandomString(Cell::header, lengthString);
        column.typeName = getRandomType();
        header.push_back(column);
    }
}

std::string Generator::getTypeAsString(Type type)
{
    std::string outPut;
    switch (type)
    {
    case Type::String:
        outPut = "String";
        break;
    case Type::Float:
        outPut = "Float";
        break;
    case Type::Integer:
        outPut = "Integer";
        break;
    case Type::Date:
        outPut = "Date";
        break;
    }
    return outPut;
}

std::string Generator::generateRandomString(Generator::Cell flag, int len)
{
    std::string outputStr = "";
    for (int i = 0; i < len; i++)
    {
        // пробел сделать последним символом и тогда вычесть из symbols.size() вместо "1" - "2", чтобы исключить пробел
        // и убрать else if где пробел заменяется на нижнее подчеркивание

        unsigned long num = static_cast<unsigned long>(randomInt(0, static_cast<int>(symbols.size()-1)));
        if (symbols[num] == delimeter)
        {
            outputStr = outputStr + "\"" + delimeter + "\"";
        }
        else if (symbols[num] == endLine)
        {
            outputStr = outputStr + "\"" + endLine + "\"";
        }
        else if (symbols[num] == quotes)
        {
            outputStr = outputStr + "\"\"";
        }
        else if(symbols[num] == whiteSpace)
        {
            if (flag == Cell::header)
            {
                outputStr = outputStr + underscore;
            }
            else
            {
                outputStr = outputStr + whiteSpace;
            }
        }
        else
        {
            outputStr += symbols[num];
        }
    }
    return  outputStr;
}



