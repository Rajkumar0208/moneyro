#ifndef MONEYRO_DATABASE_DATABASE_INCLUDED
#define MONEYRO_DATABASE_DATABASE_INCLUDED

#include "sqlite3.h"
#include <memory>

namespace Moneyro {
  namespace Database {
    class Database {
      private:
        //std::unique_ptr<sqlite3> db;
        //static std::unique_ptr<Database> instance;
        inline static Database* instance;
        Database();
      public:
        static Database* getDatabase();
        static void teste();

    };
  }

}


#endif //MONEYRO_DATABASE_DATABASE_INCLUDED
