#ifndef TST_CSVGENERATOR_H
#define TST_CSVGENERATOR_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <vector>
#include "../cmdparams.h"

using namespace testing;

struct argumentsCmdLine
{
    argumentsCmdLine(int _argc, std::vector<std::string> _argv) :
        argc(_argc),
        argv(_argv)
    {}
    int argc;
    std::vector<std::string> argv;
};

class testArgcError : public ::testing::TestWithParam<argumentsCmdLine>
{
};

INSTANTIATE_TEST_CASE_P(set, csvGenerator, ::testing::Values(
                            argumentsCmdLine(10, {1, 2, 3})
                            ));

TEST_P(csvGenerator, testArgcError)
{

}


TEST(csvGenerator, testNumColumns)
{
    EXPECT_EQ(2, 3);
    ASSERT_THAT(0, Eq(0));
}
#endif // TST_CSVGENERATOR_H
