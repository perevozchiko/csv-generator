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
const float maxFloatLength = 1000.f;
//const float maxFloatLength = std::numeric_limits<float>::max();
const int maxNumSymbolsYear = 4;
const std::string whiteSpace = " ";
const std::string delimeter = ";";
const std::string endLine = "\n"; // для линукс
const std::string quotes = "\"";
const std::string backslash = "\\";
const std::string pointer = ".";
const std::string shielding = quotes;
const std::string underscore = "_";
//const std::vector<std::string> symbols = {"а", "б", "в", "г", "д", "е", "ё", "ж", "з", "и", "й", "к", "л", "м", "н", "о", "п", "р", "с",
//                                          "т", "у", "ф", "х", "ц", "ч", "ш", "щ", "ъ", "ы", "ь", "э", "ю", "я",
//                                          "А", "Б", "В", "Г", "Д", "Е", "Ё", "Ж", "З", "И", "Й", "К", "Л", "М", "Н", "О", "П", "Р", "С",
//                                          "Т", "У", "Ф", "Х", "Ц", "Ч", "Ш", "Щ", "Ъ", "Ы", "Ь", "Э", "Ю", "Я", delimeter, quotes, underscore, pointer,
//                                          ":", "!", "#", "$", "%", "^", "&", "*", "(", ")", "-", "+", "=", "|", "{", "}", "[", "]", backslash,
//                                          "?", ",", "/", "~", "`", "'", ";", "@", "№", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0",
//                                          "a", "b", "c", "d", "e", "f", "e", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r",
//                                          "s", "t", "u", "v", "w", "x", "y", "z",
//                                          "A", "B", "C", "D", "E", "F", "E", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R",
//                                          "S", "T", "U", "V", "W", "X", "Y", "Z", whiteSpace};

const std::vector<std::string> symbols = {"а", "б", "в", "г", "д", "е", "ё", "ж", "з", "и", "й", "к", "л", "м", "н", "о", "п", "р", "с",
                                          "т", "у", "ф", "х", "ц", "ч", "ш", "щ", "ъ", "ы", "ь", "э", "ю", "я",
                                          "А", "Б", "В", "Г", "Д", "Е", "Ё", "Ж", "З", "И", "Й", "К", "Л", "М", "Н", "О", "П", "Р", "С",
                                          "Т", "У", "Ф", "Х", "Ц", "Ч", "Ш", "Щ", "Ъ", "Ы", "Ь", "Э", "Ю", "Я",
                                          "a", "b", "c", "d", "e", "f", "e", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r",
                                          "s", "t", "u", "v", "w", "x", "y", "z",
                                          "A", "B", "C", "D", "E", "F", "E", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R",
                                          "S", "T", "U", "V", "W", "X", "Y", "Z",
                                          "1", "2", "3", "4", "5", "6", "7", "8", "9", "0"};
enum Type
{
    String = 1,
    Date,
    Integer,
    Float
};

#endif // CONSTANTS_H
