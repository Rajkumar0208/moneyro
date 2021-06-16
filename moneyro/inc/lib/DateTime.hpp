#ifndef MONEYRO_DATETIME_INCLUDED
#define MONEYRO_DATETIME_INCLUDED

//#include <locale> //TODO for later

#include <chrono>

//#include <ctime> //TODO use only if necessary


namespace Moneyro {
  class DateTime {
    private:
      std::chrono::time_point<std::chrono::system_clock> timepoint;
    public:
    DateTime(std::chrono::time_point<std::chrono::system_clock> timepoint = std::chrono::system_clock::now());
  };
}

#endif //MONEYRO_DATETIME_INCLUDED
