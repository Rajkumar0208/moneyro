#include "core/PaymentCollection.hpp"

namespace Moneyro {

  PaymentCollection::PaymentCollection() {
    payments = std::vector<Payment>();
    calculateTotal();
  }

  void PaymentCollection::add(Payment newPayment){
    payments.push_back(newPayment);
    calculateTotal();
  }

  void PaymentCollection::add(std::vector<Payment> newPayments){
    payments.insert(payments.end(), newPayments.begin(), newPayments.end());
    calculateTotal();
  }

  const std::vector<Payment>& PaymentCollection::getPayments() {
    return this->payments;
  }

  void PaymentCollection::calculateTotal() {
    total = 0;
    for(auto payment: payments) {
      total += payment.getValue();
    }
  }

  long double PaymentCollection::getTotal() {
    return total;
  }
}
