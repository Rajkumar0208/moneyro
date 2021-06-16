#ifndef MONEYRO_PROFILE_INCLUDED
#define MONEYRO_PROFILE_INCLUDED

#include <vector>
#include <string>

#include "core/Payment.hpp"
#include "core/Account.hpp"

namespace Moneyro {
  class Profile {
    private:
      std::vector<Account> accounts;
      std::vector<Payment> payments;
    public:
      Profile();
      std::vector<Account> getAccounts();
      std::vector<Payment> getPayments();
  };
}
#endif //MONEYRO_PROFILE_INCLUDED
