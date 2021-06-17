#include "gtest/gtest.h"
#include "lib/DateTime.hpp"


//TODO temp
#include <string>

TEST(DateTime, DateTimeInitializationFormat) {
  Moneyro::DateTime dt;
  const char* format = "%F %T.";
  std::cout << dt.format(format) << std::endl;
}

TEST(DateTime, DateTimeInitializationFormatString) {
  Moneyro::DateTime dt;
  std::string format = "%F %T.";
  std::cout << dt.format(format) << std::endl;
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
