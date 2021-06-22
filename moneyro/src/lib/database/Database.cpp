#include "lib/database/Database.hpp"

namespace Moneyro {
  namespace Database {
    Database::Database(std::string filename) {
      //TODO modify this
      sqlite3 *db;
      rc = sqlite3_open(filename.c_str(), &db);

      if( rc ) {
        std::cout << "Can't open database:" << sqlite3_errmsg(db) << std::endl;;
      } else {
        std::cout << "Sucesso" << std::endl;;
     }
    }

    Database::~Database(){
      sqlite3_close(db);
    }
  }
}
