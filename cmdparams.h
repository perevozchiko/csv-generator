#ifndef CMDPARAMS_H
#define CMDPARAMS_H
#include <string>
#include <iostream>
#include "constants.h"

class CmdParams
{
public:
    CmdParams(int argc, char* argv[]);
    static void showUsage(std::string appName);

    int getNumColumns() const;
    void setNumColumns(int value);

    int getNumRows() const;
    void setNumRows(int value);

    int getMaxLengthValue() const;
    void setMaxLengthValue(int value);

    std::string getEncoding() const;
    void setEncoding(const std::string &value);

    std::string getOutputFileName() const;
    void setOutputFileName(const std::string &value);

private:
    int numColumns{defaultNumColumns};
    int numRows{defaultNumRows};
    int maxLengthValue{defaultMaxLengthValue};
    std::string encoding{defaultEncoding};
    std::string outputFileName;
    bool isValidArguments{true};
    void setParams(int argc, char* argv[]);
    void errorCountArguments(int count);
    bool isValid(std::string arguments);
    int checkArgNum(std::string num);
};

#endif // CMDPARAMS_H
