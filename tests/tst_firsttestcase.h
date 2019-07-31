#ifndef TST_FIRSTTESTCASE_H
#define TST_FIRSTTESTCASE_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

TEST(firstTestCase, firstTestSet)
{
    EXPECT_EQ(1, 1);
    ASSERT_THAT(0, Eq(0));
}

#endif // TST_FIRSTTESTCASE_H
