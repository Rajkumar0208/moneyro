#ifndef MONEYRO_ACCOUNT_INCLUDED
#define MONEYRO_ACCOUNT_INCLUDED

#include <string>

namespace Moneyro {
  class Account {
    private:
      std::string name;
    public:
      Account(std::string name = "Conta");
      std::string getName();
  };
}

#endif
