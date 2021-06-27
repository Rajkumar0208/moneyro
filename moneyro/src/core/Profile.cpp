#include "core/Profile.hpp"

namespace Moneyro {
  Profile::Profile(std::string filename) {

    fetchAll();
  }

  Profile::Profile(){}

  void Profile::fetchAccounts() {
    //TODO
  }

  void Profile::fetchAll() {
    //TODO
  }

  void Profile::fetchPayments() {
    //TODO
  };

  void Profile::saveAccounts() {
    //TODO
  }

  void Profile::saveAll() {
    saveAccounts();
    //savePayments();

  }

  Account* Profile::getAccountById(unsigned int id) {
    return &accounts.at(0);
  }

  std::vector<Account>* Profile::getAccounts() {
    return &accounts;
  }

  PaymentCollection* Profile::getPayments() {
    return &payments;
  }


}
