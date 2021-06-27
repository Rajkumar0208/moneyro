#ifndef MONEYRO_PROFILE_INCLUDED
#define MONEYRO_PROFILE_INCLUDED

#include <vector>
#include <string>
#include <memory>
#include <fstream>
#include <iostream>
#include <stdexcept>

#include "fmt/core.h"

#include "core/Payment.hpp"
#include "core/PaymentCollection.hpp"
#include "core/Account.hpp"
#include "json/json.h"

namespace Moneyro {
  class Profile {
    private:
      std::vector<Account> accounts;
      PaymentCollection payments;
      std::string _filename;
      void fetchAccounts();
      void fetchPayments();
      void fetchAll();
      void saveAccounts(Json::Value& root);
      void savePayments();
      void saveToJsonFile(Json::Value jsonValue, std::string filename);
    public:
      Profile(std::string filename);
      Profile();//TODO new profile
      void saveAll(std::string filename);
      void account(Account account);

      std::string filename();
      void filename(std::string filename);

      std::vector<Account>* getAccounts();
      PaymentCollection* getPayments();
      Account* getAccountById(unsigned int id);
      Json::Value getJsonFromFile();
  };
}
#endif //MONEYRO_PROFILE_INCLUDED
