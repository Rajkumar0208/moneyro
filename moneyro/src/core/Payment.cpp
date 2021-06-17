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
    return source;
  }

  Account* Payment::getDestination() {
    return destination;
  }

  void Payment::setValue(long double newValue) {
    value = newValue;
  }
}



#endif //MONEYRO_PAYMENT_INCLUDED
