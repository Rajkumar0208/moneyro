//TODO return readonly list
//
//

#ifndef MONEYRO_PAYMENT_COLLECTION_INCLUDED
#define MONEYRO_PAYMENT_COLLECTION_INCLUDED

#include <vector>
#include "core/Payment.hpp"

namespace Moneyro {
  class PaymentCollection {
    public:
      PaymentCollection();
      void add(Payment newPayment);
      void add(std::vector<Payment> newPayment);
      const std::vector<Payment>& getPayments();
      long double getTotal();
    private:
      void calculateTotal();
      long double total;
      std::vector<Payment> payments;

  };
}

#endif //MONEYRO_PAYMENT_COLLECTION_INCLUDED
