#ifndef GENERATOR_H
#define GENERATOR_H
#include <string>
#include <vector>
#include <constants.h>


class Generator
{
public:
    Generator(int _numColumns, int _maxLengthString);
    ~Generator();
    std::string getHeader();
    std::string generateRow();

private:
    struct Column
    {
        std::string columnName;
        Type typeName;
        bool isBadChar{false};
    };
    enum class Cell
    {
        header,
        simple
    };

    int numColumns;
    int maxLengthString;
    std::vector<Column> header;
    Type getRandomType();
    int randomInt(int min, int max);
    float randomFloat(float min, float max);
    bool isUnacceptableChar{false};
    std::string getRandomData();
    void generateHeader();
    std::string getTypeAsString(Type type);
    std::string generateRandomString(Cell flag, int len);

};

#endif // GENERATOR_H
