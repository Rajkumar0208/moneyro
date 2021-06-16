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
      Payment(long double value, Account* source, Account* destination);
      long double getValue();
      Account* getSource();
      Account* getDestination();
  };
}
#endif //MONEYRO_INCOME_INCLUDED
