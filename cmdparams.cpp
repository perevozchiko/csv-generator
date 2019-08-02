#include <cstring>
#include "cmdparams.h"
#include "constants.h"
#include <string>

CmdParams::CmdParams(int argc, char* argv[])
{
    appName = argv[0];
    if (argc > 1)
    {
        parseParams(argc, argv);
    }
    else
    {
        showUsage();
        return;
    }

    if (outputFileName.empty())
    {
        noErrors = false;
        std::cerr << "\nОшибка: не указано имя выходного файла. Задайте имя файла с помощью параметра \"-out <имя_выходного_файла>\"\n\n";
    }
}

CmdParams::~CmdParams()
{

}

void CmdParams::showErrNoValue(std::string option)
{
    std::cerr << "\nОшибка: не введено значение для параметра \"" << option << "\"" << std::endl << std::endl;
}

bool CmdParams::isValidOption(std::string option)
{
    if (option == "-col" ||
            option == "-row" ||
            option == "-enc" ||
            option == "-out" ||
            option == "-len" ||
            option == "-help"||
            option == "-h")
    {
        return  true;
    }

    return false;
}

void CmdParams::setParams(std::string option, std::string value)
{
    if (option == "-col" || option == "-row" || option == "-len")
    {
        long int numValue = convertToInt(value);
        if (numValue == 0)
        {
            return;
        }

        if (option == "-col")
        {
            if (numValue > maxNumColumns)
            {
                noErrors = false;
                std::cerr << "\nОшибка: введено слишком большое число для параметра -col, максимальное значение: " << maxNumColumns << std::endl << std::endl;
                return;
            }
            else
            {
                setNumColumns(numValue);
            }
        }
        else if (option == "-row")
        {
            if (numValue > maxNumRows)
            {
                noErrors = false;
                std::cerr << "\nОшибка: введено слишком большое число для параметра -row, максимальное значение: " << maxNumRows << std::endl << std::endl;
                return;
            }
            else
            {
                setNumRows(numValue);
            }
        }
        else if (option == "-len")
        {
            if (numValue > maxLength)
            {
                noErrors = false;
                std::cerr << "\nОшибка: введено слишком большое число для параметра -len, максимальное значение: " << maxLength << std::endl << std::endl;
                return;
            }
            else
            {
                setMaxLengthValue(numValue);
            }
        }
    }
    else if (option == "-out")
    {
        setOutputFileName(value);
    }
    else if(option == "-enc")
    {
        setEncoding(value);
    }
    else if (option == "-help" || option == "-h")
    {
        showUsage();
    }
}

void CmdParams::parseParams(int argc, char* argv[])
{
    for (int i = 1; i < argc; i++)
    {
        std::string option;
        std::string value;

        if (argv[i][0] == '-' && strlen(argv[i]) > 1)
        {
            option = argv[i];
            int nextArg = i + 1;

            if (nextArg < argc)
            {
                value = argv[nextArg];
                i++;
            }
        }
        else
        {
            noErrors = false;
            std::cerr << "\nОшибка: \"" << argv[i] << "\"" << " - не является параметром\n\n";
            showUsage();
            return;
        }

        if (isValidOption(option))
        {
            if (value.empty() && option != "-help" && option != "-h")
            {
                showErrNoValue(option);
            }
            else
            {
                setParams(option, value);
            }
        }
        else
        {
            noErrors = false;
            std::cerr << "\nОшибка: \"" << option << "\"" << " - неизвестный параметр\n\n";
            showUsage();
            return;
        }
    }
}

void CmdParams::showUsage()
{
    noErrors = false;
    if(appName.empty())
    {
        appName = "<имя программы>";
    }

    std::cerr << "\nИспользование:\n\t"
              << appName << "\t[-col <кол-во_колонок>] [-row <кол-во_строк>]"
                            "\n\t\t\t[-len <макс_длина_значения>] [-enc <кодировка>]"
                            "\n\t\t\t-out <имя_выходного_файла>"
              << std::endl << std::endl;

    std::cerr << "Параметры:"
                 "\n\t-col\tУстановить количество колонок, значение по умолчанию \"" << defaultNumColumns << "\", максимальное значение: \"" << maxNumColumns << "\""
              << "\n\t-row\tУстановить количество строк, значение по умолчанию \"" << defaultNumRows << "\" максимальное значение: \"" << maxNumRows << "\""
              << "\n\t-len\tУстановить максимальную длину для строкового типа, значение по умолчанию \"" << defaultMaxLengthValue << "\""
              << "\n\t-enc\tУстановить кодировку, значение по умолчанию \"" << defaultEncoding << "\""
              << "\n\t-out\tУстановить имя выходного файла (обязательный параметр)"
              << std::endl << std::endl;
}

int CmdParams::getNumColumns() const
{
    return numColumns;
}

int CmdParams::convertToInt(std::string value)
{
    std::string number;
    for (size_t i = 0; i < value.size(); i++)
    {
        if(isdigit(value[i]))
        {
            number += value[i];
        }
        else
        {
            noErrors = false;
            std::cerr << "\nОшибка: \""<< value <<"\" - должно быть целое положительное число\n\n";
            number = "";
            break;
        }
    }
    long int inputNum = 0;
    if (!number.empty())
    {
        inputNum = std::stoll(value);
    }

    return inputNum;
}

void CmdParams::setNumColumns(int value)
{
    numColumns = value;
}

int CmdParams::getNumRows() const
{
    return numRows;
}

void CmdParams::setNumRows(int value)
{
    numRows = value;
}

int CmdParams::getMaxLengthValue() const
{
    return maxLengthValue;
}

void CmdParams::setMaxLengthValue(int value)
{
    maxLengthValue = value;
}

std::string CmdParams::getEncoding() const
{
    return encoding;
}

void CmdParams::setEncoding(const std::string &value)
{
    encoding = value;
}

std::string CmdParams::getOutputFileName() const
{
    return outputFileName;
}

void CmdParams::setOutputFileName(const std::string &value)
{
    outputFileName = value;
}

bool CmdParams::isValid()
{
    return noErrors;
}


