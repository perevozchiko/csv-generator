#ifndef TST_CSVGENERATOR_H
#define TST_CSVGENERATOR_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <vector>
#include <cstdarg>
#include "../../cmdparams.h"
#include "../../constants.h"


using namespace testing;

void convertToArray(char** arr, std::vector<char*> vector)
{
    for(unsigned int i = 0; i < vector.size(); i++)
    {
        arr[i] = &vector[i][0];
    }
}

std::vector<char*> createArgv(int count, ...)
{
    va_list args;
    std::vector<char*> outputArgs;
    va_start(args, count);
    for (int i = 0; i < count; i++)
    {
        outputArgs.push_back(va_arg(args, char*));
    }
    va_end(args);
    return outputArgs;
}

struct argumentsCmdLine
{
    argumentsCmdLine(int _argc, std::vector<char*> _argv, std::string _result) :
        argc(_argc),
        argv(_argv),
        result(_result)

    {}
    int argc;
    std::vector<char*> argv;
    std::string result;
};

class testArgcArgvError : public ::testing::TestWithParam<argumentsCmdLine>
{
};

INSTANTIATE_TEST_CASE_P(set, testArgcArgvError, ::testing::Values(
                            argumentsCmdLine(5, createArgv(5, "234"), "t")
                            ),);

TEST_P(testArgcArgvError, csvGenerator)
{
    const auto param = GetParam();
    char** arr = new char*[param.argv.size()];
    convertToArray(arr, param.argv);
    CmdParams cmdParams(param.argc, arr);
    std::string capturedStdout = ::testing::internal::GetCapturedStdout().c_str();
    EXPECT_STREQ(capturedStdout, "hello");

}


//TEST(csvGenerator, testNumColumns)
//{
//    EXPECT_EQ(2, 3);
//    ASSERT_THAT(0, Eq(0));
//}
#endif // TST_CSVGENERATOR_H
