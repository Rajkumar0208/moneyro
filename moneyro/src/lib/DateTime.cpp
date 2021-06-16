#include "lib/DateTime.hpp"

namespace Moneyro {

  DateTime::DateTime(std::chrono::time_point<std::chrono::system_clock> timepoint) {
    this->timepoint = timepoint;
  }
}
