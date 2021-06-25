#include "core/Profile.hpp"

namespace Moneyro {
  Profile::Profile(std::string filename) {
    database = std::make_unique<Database::Database>(filename);

    fetchAll();
  }

  Profile::Profile(){}

  void Profile::fetchAccounts() {
    for(auto row: database->query("select id, name from Account")){
      accounts.push_back(Account(std::stoi(row["id"]), row["name"]));
    }
  }

  void Profile::fetchAll() {
    fetchAccounts();
    fetchPayments();
  }

  void Profile::fetchPayments() {
    std::vector<Payment> payments {};
    for(auto row: database->query("select id, value from Payment")){
      payments.push_back(Payment(std::stol(row["value"]), getAccountById(0)));
    }
    this->payments.add(payments);
  };

  void Profile::saveAccounts() {
    std::string sql = "";

    for(auto account: accounts){
      if(static_cast<bool>(account.id())) {
        sql += fmt::format("UPDATE account SET name = \"{}\" WHERE id = {};", account.name(), account.id());
      } else {
        sql += fmt::format("INSERT INTO account (name) VALUES(\"{}\");", account.name());
      }
    }

    database->query(sql);
  }

  void Profile::saveAll() {
    saveAccounts();

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
