#include "core/Profile.hpp"

namespace Moneyro {
  Profile::Profile(std::string filename) {
    _filename = filename;

    fetchAll();
  }

  Profile::Profile(){

  }

  void Profile::fetchAccounts() {
    //TODO
  }

  void Profile::fetchAll() {
    //TODO
  }

  void Profile::fetchPayments() {
    //TODO
  };

 void Profile::saveAccounts(Json::Value& root) {
    Json::Value accountsJson;

    for(auto account : accounts){
      Json::Value accountJson;
      accountJson["name"] = Json::Value(account.name());
      accountsJson.append(accountJson);
    }

    root["accounts"] = accountsJson;
  }

  void Profile::saveAll(std::string filename) {
    //if(filename == NULL){
    //TODO add exceeption if filename is null
    //  throw std::runtime_exception("filename is null");
    //}
    
    Json::Value root;

    saveAccounts(root);



    saveToJsonFile(root, filename);
  }

  void Profile::filename(std::string filename){
    _filename = filename;
  }

  std::string Profile::filename() {
    return _filename;
  }

  Account* Profile::getAccountById(unsigned int id) {
    return &accounts.at(0);
  }

  void Profile::account(Account account){
    accounts.push_back(account);
  }
  std::vector<Account>* Profile::getAccounts() {
    return &accounts;
  }

  PaymentCollection* Profile::getPayments() {
    return &payments;
  }

  void Profile::saveToJsonFile(Json::Value jsonValue, std::string filename) {
    //std::ofstream(filename, std::ios::binary) << jsonValue;
    std::ofstream(filename, std::ios::binary) << jsonValue;

  }

  Json::Value Profile::getJsonFromFile() {
    Json::Value jsonVal;
    return jsonVal;
  }
}
