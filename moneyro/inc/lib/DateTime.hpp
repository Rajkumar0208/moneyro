#ifndef MONEYRO_DATETIME_INCLUDED
#define MONEYRO_DATETIME_INCLUDED

#include <locale>
#include <chrono>
#include <ctime>
#include <string>
#include <iomanip>
#include <sstream>
#include <cstdlib>

namespace Moneyro {

  using Clock = std::chrono::system_clock;
  using TimePoint = std::chrono::time_point<Clock>;

  class DateTime {
    using microseconds = std::chrono::microseconds;
    using milliseconds = std::chrono::milliseconds;
    using seconds = std::chrono::seconds;
    using minutes = std::chrono::minutes;
    using hours = std::chrono::hours;
    using days = std::chrono::duration<int, std::ratio<86400>>;
    using weeks = std::chrono::duration<int, std::ratio<604800>>;
    using months = std::chrono::duration<int, std::ratio<2629746>>;
    using years = std::chrono::duration<int, std::ratio<31556952>>;

    private:
      TimePoint timepoint;
      std::time_t from_format(std::string parseString, std::string format);
    public:
      DateTime(TimePoint timepoint = Clock::now());
      DateTime(std::string parseString, std::string format);
      std::string format(std::string format);
      void sum(Clock::duration duration);
      const TimePoint toTimePoint();
      const std::time_t toTimeT();
  };
}

#endif //MONEYRO_DATETIME_INCLUDED
