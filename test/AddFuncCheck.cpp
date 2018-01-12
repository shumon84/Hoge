#include <add.h>
#include <gtest/gtest.h>

namespace {
  class MyLibTest : public ::testing::Test{};

  TEST_F(MyLibTest, AddFuncCheck) {
    EXPECT_EQ(add(3.0,1.0), 4.0);
    EXPECT_EQ(add(-12,5), -7);
  }
}
