#include "lib/DateTime.hpp"

namespace Moneyro {

  //TODO use duration ::hours to parse Date in static method
  DateTime::DateTime(std::chrono::time_point<std::chrono::system_clock> timepoint) {
    this->timepoint = timepoint;
    this->time_c = std::chrono::system_clock::to_time_t(timepoint);
  }

  std::string DateTime::format(std::string formatString) {
    return format(formatString.c_str());
  }

  std::string DateTime::format(const char* formatString) {
    std::ostringstream stream;
    stream << std::put_time(std::localtime(&time_c), formatString);
    return stream.str();
  }
}
