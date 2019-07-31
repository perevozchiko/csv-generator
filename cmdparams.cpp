#include <cstring>
#include "cmdparams.h"
#include "constants.h"


CmdParams::CmdParams(int argc, char* argv[])
{
        cmdParse(argc, argv);
}

void CmdParams::cmdParse(int argc, char* argv[])
{
    for (int i = 1; i < argc; i++)
    {
        if (!(strcmp(argv[i], "-col")))
        {
            i++;
            numColumns = atoi(argv[i]);
        }
        if (!(strcmp(argv[i], "-row")))
        {
            i++;
            numRows = atoi(argv[i]);
        }
        if (!(strcmp(argv[i], "-len")))
        {
            i++;
            maxLengthValue = atoi(argv[i]);
        }
        if (!(strcmp(argv[i], "-enc")))
        {
            i++;
            encoding = argv[i];
        }
        if (!(strcmp(argv[i], "-out")))
        {
            i++;
            outputFileName = argv[i];
        }
        if (!(strcmp(argv[i], "-help")))
        {
            help();
        }
    }
}

void CmdParams::errorCountArguments(int count)
{
    if (count == 1)
    {
       help();
    }
    else if(count > amountArgs-1)
    {
        std::cerr << "Введено слишком большое количество аргументов.\nНеобходимое количество аргументов: 10, а введено: " << count-1 << "\n" ;
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

void CmdParams::help()
{
    std::cout << "Использование: gen_csv.exe [–col кол-во_колонок] [–row кол-во_строк] [-len макс_длина_значения] [-enc кодировка] –out имя_выходного_файла\n";
    return;
}


