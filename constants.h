#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <string>
#include <vector>
#include <limits>

// Необходимое количество аргументов при вызове из командной строки
const int amountArgs = 10;
const int defaultNumRows = 10;
const int defaultNumColumns = 5;
const int defaultMaxLengthValue = 10;
const std::string defaultEncoding = "UTF-8";
const int maxNumColumns = 1000;
const int maxNumRows = 1e6;
const int maxIntLength = std::numeric_limits<int>::max();
const float maxFloatLength = std::numeric_limits<float>::max();
const std::string whiteSpace = " ";
const std::string delimeter = ";";
const std::string endLine = "\n\r";
const std::string quotes = "\"";
const std::string pointer = ".";
const std::string underscore = "_";
const std::vector<std::string> symbols = {"а", "б", "в", "г", "д", "е", "ё", "ж", "з", "и", "й", "к", "л", "м", "н", "о", "п", "р", "с",
                                          "т", "у", "ф", "х", "ц", "ч", "ш", "щ", "ъ", "ы", "ь", "э", "ю", "я",
                                          "А", "Б", "В", "Г", "Д", "Е", "Ё", "Ж", "З", "И", "Й", "К", "Л", "М", "Н", "О", "П", "Р", "С",
                                          "Т", "У", "Ф", "Х", "Ц", "Ч", "Ш", "Щ", "Ъ", "Ы", "Ь", "Э", "Ю", "Я", delimeter, quotes, endLine, underscore, pointer,
                                          ":", "!", "#", "$", "%", "^", "&", "*", "(", ")", "-", "+", "=", "|", "{", "}", "[", "]",
                                          "?", ",", "/", "~", "`", "'", ";", "@", "№", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", whiteSpace};
enum Type
{
    String = 1,
    Date,
    Integer,
    Float
};


#endif // CONSTANTS_H
