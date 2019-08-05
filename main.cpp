#include <iostream>
#include "cmdparams.h"
#include <typeinfo>
#include <vector>
#include <fstream>
#include "generator.h"




int main(int argc, char* argv[])
{
    CmdParams params(argc, argv);

    if (params.isValid())
    {
        std::string fileName = params.getOutputFileName();

        if(fileName.substr(fileName.size()-4, 4) != ".csv")
        {
            fileName += ".csv";
        }

        std::ofstream file(fileName);

        if(!file)
        {
            std::cerr << "\nОшибка: невозможно создать файл по указанному пути \"" << fileName << "\"\n\n";
            return 0;
        }

        Generator gen(params.getNumColumns(), params.getMaxLengthValue());
        if (params.getEncoding() == defaultEncoding)
        {
            file << BOM;
        }
        file << gen.getHeader();

        for (int i = 0; i < params.getNumRows(); i++)
        {
            file << gen.generateRow();
        }
        file.close();



        //        std::cout << "\n\n\t\tARGS\n\n";
        //        std::cout << "rows: " << params.getNumRows() << std::endl;
        //        std::cout << "columns: " << params.getNumColumns() << std::endl;
        //        std::cout << "length: " << params.getMaxLengthValue() << std::endl;
        //        std::cout << "encodin: " << params.getEncoding() << std::endl;
        //        std::cout << "outfile: " << params.getOutputFileName() << std::endl;
    }
    return 0;
}

