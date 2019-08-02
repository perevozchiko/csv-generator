#include <iostream>
#include "cmdparams.h"
#include <typeinfo>
#include <vector>




int main(int argc, char* argv[])
{
    CmdParams params(argc, argv);

    if (params.isValid())
    {

        std::cout << "\n\n\t\tARGS\n\n";
        std::cout << "rows: " << params.getNumRows() << std::endl;
        std::cout << "columns: " << params.getNumColumns() << std::endl;
        std::cout << "length: " << params.getMaxLengthValue() << std::endl;
        std::cout << "encodin: " << params.getEncoding() << std::endl;
        std::cout << "outfile: " << params.getOutputFileName() << std::endl;
    }
    return 0;
}

