#ifndef MONEYRO_DATETIME_INCLUDED
#define MONEYRO_DATETIME_INCLUDED

//#include <locale> //TODO for later

#include <chrono>
#include <ctime>
#include <string>
#include <iomanip>

namespace Moneyro {
  class DateTime {
    private:
      std::chrono::time_point<std::chrono::system_clock> timepoint;
      std::time_t time_c;
    public:
    DateTime(std::chrono::time_point<std::chrono::system_clock> timepoint = std::chrono::system_clock::now());
    std::string format(std::string format);
    std::string format(const char* format);
  };
}

#endif //MONEYRO_DATETIME_INCLUDED
