#include "database/Database.hpp"

namespace Moneyro {
  namespace Database {
    Database::Database() {

    }

    Database* Database::getDatabase() {
      if(!instance)
        instance = new Database(); //std::make_unique<Database>();

      return instance;
    }

  }

}
