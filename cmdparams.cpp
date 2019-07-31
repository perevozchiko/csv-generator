#include "cmdparams.h"
#include <cstring>


CmdParams::CmdParams(int argc, char* argv[])
{
    cmdParse(argc, argv);
}


void CmdParams::cmdParse(int argc, char* argv[])
{
    if (argc == 10)
    {

    }
    else
    {
        std::cerr << "Недостаточно аргументов\n";
        return;
    }

    if (argc > 1)
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
        }
    }
    else
    {
        std::cerr << "Нет аргументов\n";
    }
}
