#include "gtest/gtest.h"
#include "core/Profile.hpp"
#include <memory>

TEST(Profile, SaveJsonToFile){
  using namespace Moneyro;
  Profile profile;

  std::string filename = "test_profile.json";

  profile.account(Account("Cartão de crédito"));
  profile.account(Account("Conta Banco X"));
  profile.account(Account("Conta Banco Y"));



  profile.saveAll(filename);
}
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
