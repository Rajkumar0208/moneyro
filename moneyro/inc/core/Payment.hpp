#ifndef MONEYRO_INCOME_INCLUDED
#define MONEYRO_INCOME_INCLUDED

#include "core/Account.hpp"
#include "core/Category.hpp"
#include "lib/DateTime.hpp"

namespace Moneyro {
  class Payment {
    private:
      long double value;
      Account* account; //TODO ptr
      DateTime issueDate;
      //Category category; //TODO ptr
      //Issue Date
      //Due Date
    public:
      Payment(long double value, Account* account, DateTime issueDate = DateTime());
      long double getValue();
      //TODO exceptions when pointer is emtpy
      Account* getAccount();
      DateTime getIssueDate();
      void setValue(long double newValue);

  };
}
#endif //MONEYRO_INCOME_INCLUDED
