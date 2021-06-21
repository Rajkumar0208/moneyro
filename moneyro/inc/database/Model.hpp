#ifndef MONEYRO_DATABASE_MODEL_INCLUDED
#define MONEYRO_DATABASE_MODEL_INCLUDED

#include "database/Database.hpp"

namespace Moneyro {
  namespace Database {
    template<class T>
    class Model {
      private:
        Database* database;
      public:
        Model(Database* database);
        void save();
        static T all();
    };
  }
}


#endif //MONEYRO_DATABASE_MODEL_INCLUDED
