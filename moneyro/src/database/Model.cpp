#include "database/Model.hpp"

namespace Moneyro {
  namespace Database {
    Model::Model(Database* database) {
      this->db = database;
    }
  }
}
