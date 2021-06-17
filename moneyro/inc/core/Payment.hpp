#ifndef MONEYRO_INCOME_INCLUDED
#define MONEYRO_INCOME_INCLUDED

#include "core/Account.hpp"
#include "core/Category.hpp"

namespace Moneyro {
  class Payment {
    private:
      long double value;
      Account* source; //TODO ptr
      Account* destination; //TODO ptr
      //Category category; //TODO ptr
      //Issue Date
      //Due Date
    public:
      Payment(long double value = 0, Account* source = nullptr, Account* destination = nullptr);
      long double getValue();
      Account* getSource();
      Account* getDestination();
      void setValue(long double newValue);
  };
}
#endif //MONEYRO_INCOME_INCLUDED
