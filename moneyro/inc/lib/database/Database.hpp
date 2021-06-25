#ifndef MONEYRO_DATABASE_DATABASE_INCLUDED
#define MONEYRO_DATABASE_DATABASE_INCLUDED

#include "sqlite3.h"
#include <memory>
#include <string>
#include <map>
#include <functional>

//TODO remove iostream
#include<iostream>


namespace Moneyro {
  namespace Database {
    class Database {
      private:
        sqlite3 *db;
        std::string filename;
        int rc;
        static int callbackHandler(void *data, int argc, char **argv, char **azColName);
      public:
        std::vector<std::map<std::string, std::string>> query(std::string sql);
        Database(std::string filename);
        ~Database();
    };
  }

}


#endif //MONEYRO_DATABASE_DATABASE_INCLUDED
