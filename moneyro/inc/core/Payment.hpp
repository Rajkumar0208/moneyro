#ifndef MONEYRO_INCOME_INCLUDED
#define MONEYRO_INCOME_INCLUDED

#include "core/Account.hpp"
#include "core/Category.hpp"
#include "lib/DateTime.hpp"

namespace Moneyro {
  class Payment {
    private:
      long double value;
      Account* source; //TODO ptr
      Account* destination; //TODO ptr
      DateTime issueDate;
      //Category category; //TODO ptr
      //Issue Date
      //Due Date
    public:
      Payment(long double value = 0, Account* destination = nullptr, Account* source = nullptr, DateTime issueDate = DateTime());
      long double getValue();
      //TODO exceptions when pointer is emtpy
      Account* getSource();
      Account* getDestination();
      DateTime getIssueDate();
      void setValue(long double newValue);

  };
}
#endif //MONEYRO_INCOME_INCLUDED
