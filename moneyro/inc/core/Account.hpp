#ifndef MONEYRO_ACCOUNT_INCLUDED
#define MONEYRO_ACCOUNT_INCLUDED

#include <string>
#include <optional>

namespace Moneyro {
  class Account {
    private:
      unsigned int _id;
      std::string _name;
    public:
      Account(std::string name = "Conta");
      Account(unsigned int id, std::string name);
      std::string name();
      unsigned int id();
      void name(std::string name);
  };
}

#endif
