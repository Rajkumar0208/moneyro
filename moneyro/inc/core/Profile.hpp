#ifndef MONEYRO_PROFILE_INCLUDED
#define MONEYRO_PROFILE_INCLUDED

#include <vector>
#include <string>
#include <memory>

#include "fmt/core.h"

#include "core/Payment.hpp"
#include "core/PaymentCollection.hpp"
#include "core/Account.hpp"
#include "lib/database/Database.hpp"

namespace Moneyro {
  class Profile {
    private:
      std::unique_ptr<Database::Database> database;
      std::vector<Account> accounts;
      PaymentCollection payments;
      void fetchAccounts();
      void fetchPayments();
      void fetchAll();
      void saveAccounts();
      void savePayments();
    public:
      Profile(std::string filename);
      Profile();//TODO new profile
      void saveAll();
      std::vector<Account>* getAccounts();
      PaymentCollection* getPayments();
      Account* getAccountById(unsigned int id);


  };
}
#endif //MONEYRO_PROFILE_INCLUDED
