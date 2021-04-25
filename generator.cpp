#include "generator.h"
#include <random>
#include <ctime>
#include <iostream>
#include <algorithm>

Generator::Generator(int _numColumns, int _maxLengthString) :
    numColumns(_numColumns),
    maxLengthString(_maxLengthString)
{
    //    std::cout << symbols.size() << std::endl;
    //    std::cout << symbols[symbols.size()-1] << std::endl;
}

Generator::~Generator()
{

}

std::string Generator::generateRow()
{
    std::string row = "";

    for (size_t i = 0; i < header.size(); i++)
    {
        Column col = header[i];
        std::string value;
        switch (col.typeName)
        {
        case Type::String:
        {
            int length = randomInt(1, maxLengthString);
            value += generateRandomString(Cell::simple, length);
            if (isUnacceptableChar)
            {
                value = shielding + value + shielding;
                isUnacceptableChar = false;
            }
            break;
        }
        case Type::Integer:
        {
            value += std::to_string(randomInt(0, maxIntLength));
            break;
        }
        case Type::Float:
        {
            float randomFloatNum = randomFloat(0, maxFloatLength);
            value += std::to_string(randomFloatNum);
            std::replace(value.begin(), value.end(), '.', ',');
            break;
        }
        case Type::Date:
        {
            value += getRandomData();
        }
        }

        if (i != (header.size()-1))
        {
            value += delimeter;
        }
        else
        {
            value += endLine;
        }
        row += value;
    }

    //std::cout << row << std::endl;
    return  row;
}

std::string Generator::getHeader()
{
    generateHeader();

    //    for (int i = 0; i < header.size(); i++)
    //    {
    //        std::cout << header[i].columnName << std::endl;
    //        std::cout << header[i].typeName << std::endl;
    //        std::cout << header[i].isBadChar << std::endl;
    //        std::cout << "\n-------------------------------\n" << std::endl;
    //    }

    std::string outputData ="";
    for(size_t i = 0; i < header.size(); i++)
    {
        std::string columnData = header[i].columnName +
                whiteSpace +
                getTypeAsString(header[i].typeName);

        if (header[i].isBadChar)
        {
            columnData = shielding + columnData + shielding;
        }

        if (i != header.size()-1)
        {
            columnData += delimeter;
        }
        else
        {
            columnData += endLine;
        }
        outputData += columnData;
    }

  // std::cout << outputData << std::endl;
    return  outputData;
}

Type Generator::getRandomType()
{
    int randomNum = randomInt(1,4);
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
    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 gen(rd());    // random-number engine used (Mersenne-Twister in this case)
    std::uniform_real_distribution<double> dis(min, max); // guaranteed unbiased

    return static_cast<float>(dis(gen));
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
    unsigned long additionalZeros = maxNumSymbolsYear - yearStr.size();
    while (additionalZeros--)
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
        column.isBadChar = isUnacceptableChar;
        isUnacceptableChar = false;
        column.typeName = getRandomType();
        header.push_back(column);
    }
    //    for (int i = 0; i < header.size(); i++)
    //    {
    //        std::cout << header[i].columnName << std::endl;
    //        std::cout << header[i].typeName << std::endl;
    //        std::cout << header[i].isBadChar << std::endl;
    //        std::cout << "\n-------------------------------\n" << std::endl;
    //    }
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
        unsigned long num = static_cast<unsigned long>(randomInt(0, static_cast<int>(symbols.size()-1)));

        if (symbols[num] == delimeter || symbols[num] == quotes)
        {
            isUnacceptableChar = true;
        }
        if (symbols[num] == quotes)
        {
            outputStr += shielding;
        }

        if(symbols[num] == whiteSpace)
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
