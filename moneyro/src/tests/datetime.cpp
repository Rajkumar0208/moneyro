#include "gtest/gtest.h"
#include "lib/DateTime.hpp"


#include <string>

TEST(DateTime, DateTimeInitYearMonthDayHoursMinutesSecondsParamsA) {
  std::string outputFormat = "%F %T";

  Moneyro::DateTime dt("2020-02-01", "%Y-%m-%d");
  EXPECT_EQ(dt.format(outputFormat), "2020-02-01 00:00:00");

  //Test invalid values
  Moneyro::DateTime dtA("2020-02-00", "%Y-%m-%d");
  EXPECT_EQ(dtA.format(outputFormat), "2020-01-31 00:00:00");
}

TEST(DateTime, DateTimeSum) {
  std::string outputFormat = "%F %T";
  Moneyro::DateTime dt("2020-02-01", "%Y-%m-%d");

  dt.sum(std::chrono::hours(1));
  EXPECT_EQ(dt.format(outputFormat), "2020-02-01 01:00:00");


  dt.sum(std::chrono::hours(24));
  EXPECT_EQ(dt.format(outputFormat), "2020-02-02 01:00:00");

  dt.sum(std::chrono::minutes(32));
  EXPECT_EQ(dt.format(outputFormat), "2020-02-02 01:32:00");

  dt.sum(std::chrono::minutes(-32));
  EXPECT_EQ(dt.format(outputFormat), "2020-02-02 01:00:00");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
