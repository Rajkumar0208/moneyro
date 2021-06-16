#include "core/Account.hpp"

namespace Moneyro {
  Account::Account(std::string name) {
    this->name = name;
  }

  std::string Account::getName() {
    return this->name;
  }
}
