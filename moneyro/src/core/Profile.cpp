#include "core/Profile.hpp"

namespace Moneyro {
  Profile::Profile(std::string filename){
    database = Database::Database(filename);
    this->accounts = {};
    this->payments = {};
  }

}
