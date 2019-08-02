#ifndef GENERATOR_H
#define GENERATOR_H
#include <string>


class Generator
{
public:
    Generator(int _numColumns, int _length);
    ~Generator();

private:
    int numColumns;
    int length;
    std::string generateRow();
    std::string generateHeader();
};

#endif // GENERATOR_H
