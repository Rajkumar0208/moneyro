//TODO return readonly list
//
//

#ifndef MONEYRO_PAYMENT_COLLECTION_INCLUDED
#define MONEYRO_PAYMENT_COLLECTION_INCLUDED

#include <vector>
#include "core/Payment.hpp"

namespace Moneyro {
  class PaymentCollection {
      std::vector<Payment> payments;
  };
}



#endif //MONEYRO_PAYMENT_COLLECTION_INCLUDED
