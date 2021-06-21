#ifndef MONEYRO_PAYMENT_INCLUDED
#define MONEYRO_PAYMENT_INCLUDED

#include "core/Payment.hpp"

namespace Moneyro {
  Payment::Payment(double long value, Account* account, DateTime issueDate) { //: Database::Model<Payment>(Database::Database::getDatabase()){
    this->value = value;
    this->account = account;
  };

  long double Payment::getValue() {
    return this->value;
  }

  Account* Payment::getAccount() {
    return account;
  }

  void Payment::save() {
    //TODO
  }


  void Payment::setValue(long double newValue) {
    value = newValue;
  }

  DateTime Payment::getIssueDate() {
    return issueDate;
  }
}



#endif //MONEYRO_PAYMENT_INCLUDED
