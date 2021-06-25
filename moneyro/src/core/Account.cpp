#include "core/Account.hpp"

namespace Moneyro {
  Account::Account(std::string name) {
    _id = 0; 
    _name = name;
  }

  Account::Account(unsigned int id, std::string name) {
    _id = id;
    _name = name;
  }

  std::string Account::name() {
    return _name;
  }

  void Account::name(std::string name) {
    _name = name;
  }

  unsigned int Account::id(){
    return _id;
  }
}
