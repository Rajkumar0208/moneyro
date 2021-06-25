#include "lib/database/Database.hpp"

namespace Moneyro {
  namespace Database {
    Database::Database(std::string filename) {
      this->filename = filename;
    }

    Database::~Database(){
      sqlite3_close(db);
    }

    int Database::callbackHandler(void *data, int argc, char **argv, char **azColName) {
      std::function<void(int argc, char **argv, char **azColName)>* callback = reinterpret_cast<std::function<void(int argc, char **argv, char **azColName)>*>(data);

      (*callback)(argc, argv, azColName);

      return 0;
    }

    std::vector<std::map<std::string, std::string>> Database::query(std::string sql) {
      std::vector<std::map<std::string, std::string>> result;

      rc = sqlite3_open(filename.c_str(), &db);

      char* zErrMsg = 0;

      std::function<void(int argc, char **argv, char **azColName)> callback = [&result](int argc, char **argv, char **azColName){
        std::map<std::string, std::string> row;
        for(int i = 0; i<argc; i++){
          row.insert({std::string(azColName[i]), std::string(argv[i])});
        }

        result.push_back(row);
      };


      rc = sqlite3_exec(db, sql.c_str(), callbackHandler, &callback, &zErrMsg);

      if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
      }

      sqlite3_close(db);

      return result;
    }
  }
}
