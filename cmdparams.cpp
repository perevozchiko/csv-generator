#include <cstring>
#include "cmdparams.h"
#include "constants.h"

CmdParams::CmdParams(int argc, char* argv[])
{
    if (argc > 1)
    {
        setParams(argc, argv);
    }
    else
    {
        showUsage(argv[0]);
    }
}

void CmdParams::setParams(int argc, char* argv[])
{
    if (argc == 2 && (strcmp(argv[1], "-help") == 0 || strcmp(argv[1], "-h") == 0))
    {
        showUsage(argv[0]);
    }

    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-col") == 0)
        {
            if(i+1 < argc)
            {

            }
            numColumns = atoi(argv[i]);
        }
        if (strcmp(argv[i], "-row") == 0)
        {
            i++;
            numRows = atoi(argv[i]);
        }
        if (strcmp(argv[i], "-len") == 0)
        {
            i++;
            maxLengthValue = atoi(argv[i]);
        }
        if (strcmp(argv[i], "-enc") == 0)
        {
            i++;
            encoding = argv[i];
        }
        if (strcmp(argv[i], "-out") == 0)
        {
            i++;
            outputFileName = argv[i];
        }
    }
}



void CmdParams::errorCountArguments(int count)
{
    if(count > amountArgs-1)
    {
        std::cerr << ", а введено: " << count-1 << std::endl ;
    }
    else if(count < amountArgs-1)
    {
        std::cerr << "Введено недостаточное количество аргументов.\nНеобходимое количество аргументов: 10, а введено: " << count-1 << "\n" ;
    }
    else
    {
        std::cerr << "Неизвестная ошибка\n";
    }
}

bool CmdParams::isValid(std::string arguments)
{
    return false;
}


void CmdParams::showUsage(std::string appName)
{
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
                 "\n\t-col\tКоличество колонок, значение по умолчанию \"" << defaultNumColumns << "\""
              << "\n\t-row\tКоличество строк, значение по умолчанию \"" << defaultNumRows << "\""
              << "\n\t-len\tМаксимальная длина значения для строкового типа, значение по умолчанию \"" << defaultMaxLengthValue << "\""
              << "\n\t-enc\tКодировка, значение по умолчанию \"" << defaultEncoding << "\""
              << "\n\t-out\tИмя выходного файла (обязательный параметр)"
              << std::endl << std::endl;
}


