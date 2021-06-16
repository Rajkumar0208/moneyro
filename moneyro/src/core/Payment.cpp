#ifndef MONEYRO_PAYMENT_INCLUDED
#define MONEYRO_PAYMENT_INCLUDED

#include "core/Payment.hpp"

namespace Moneyro {
  Payment::Payment(double long value, Account* source, Account* destination) {
    this->value = value;
    this->source = source;
    this->destination = destination;
  };
  long double Payment::getValue() {
    return this->value;
  }

  Account* Payment::getSource() {
    return this->source;
  }

  Account* Payment::getDestination() {
    return this->destination;
  }
}



#endif //MONEYRO_PAYMENT_INCLUDED
