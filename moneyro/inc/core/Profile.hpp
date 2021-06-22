#ifndef MONEYRO_PROFILE_INCLUDED
#define MONEYRO_PROFILE_INCLUDED

#include <vector>
#include <string>

#include "core/Payment.hpp"
#include "core/Account.hpp"
#include "lib/database/Database.hpp"

namespace Moneyro {
  class Profile {
    private:
      std::vector<Account> accounts;
      std::vector<Payment> payments;
      Database::Database database;
    public:
      Profile(std::string filename);
      std::vector<Account> getAccounts();
      std::vector<Payment> getPayments();

  };
}
#endif //MONEYRO_PROFILE_INCLUDED
