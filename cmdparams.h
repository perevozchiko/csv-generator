#ifndef CMDPARAMS_H
#define CMDPARAMS_H
#include <string>
#include <iostream>
#include "constants.h"

class CmdParams
{
public:
    CmdParams(int argc, char* argv[]);
    ~CmdParams();
    void showUsage();

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

    bool isValid();

private:    
    int numColumns{defaultNumColumns};
    int numRows{defaultNumRows};
    int maxLengthValue{defaultMaxLengthValue};
    std::string encoding{defaultEncoding};
    std::string outputFileName;
    std::string appName;
    bool noErrors{true};
    void parseParams(int argc, char* argv[]);
    void errorCountArguments(int count);
    int checkArgNum(std::string num);
    int convertToInt(std::string value);
    void showErrNoValue(std::string option);
    bool isValidOption(std::string option);
    void setParams(std::string option, std::string value);

};

#endif // CMDPARAMS_H
