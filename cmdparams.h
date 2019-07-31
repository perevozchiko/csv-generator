#ifndef CMDPARAMS_H
#define CMDPARAMS_H
#include <string>
#include <iostream>

class CmdParams
{
public:
    CmdParams(int argc, char* argv[]);

private:
    int numColumns;
    int numRows;
    int maxLengthValue;
    std::string encoding;
    std::string outputFileName;
    void cmdParse(int argc, char* argv[]);
    void errorCountArguments(int count);
    void help();
};

#endif // CMDPARAMS_H
