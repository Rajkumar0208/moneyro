#ifndef MONEYRO_DATABASE_DATABASE_INCLUDED
#define MONEYRO_DATABASE_DATABASE_INCLUDED

#include "sqlite3.h"
#include <memory>
#include <string>

//TODO remove iostream
#include<iostream>


namespace Moneyro {
  namespace Database {
    class Database {
      private:
        sqlite3 *db;
        int rc;
      public:
        Database(std::string filename);
        ~Database();
    };
  }

}


#endif //MONEYRO_DATABASE_DATABASE_INCLUDED
