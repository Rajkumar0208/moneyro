#include "lib/DateTime.hpp"

namespace Moneyro {

  DateTime::DateTime(TimePoint timepoint) {
    this->timepoint = timepoint;
  }

  DateTime::DateTime(std::string parseString, std::string format) {
    std::time_t t = from_format(parseString, format);
    timepoint = TimePoint(Clock::from_time_t(t));
  }

  std::time_t DateTime::from_format(std::string parseString, std::string format) {
    std::tm tm = {};
    std::istringstream ss(parseString.c_str());
    ss.imbue(std::locale("C"));
    ss >> std::get_time(&tm, format.c_str());

    return std::mktime(&tm);
  }

  std::string DateTime::format(std::string formatString) {
    auto time_c = std::chrono::system_clock::to_time_t(timepoint);
    std::ostringstream stream;
    stream << std::put_time(std::localtime(&time_c), formatString.c_str());
    return stream.str();
  }

  //TODO operators
  void DateTime::sum(Clock::duration duration) {
    timepoint = timepoint + duration;
  }

  const TimePoint DateTime::toTimePoint() {
    return timepoint;
  };

  const std::time_t DateTime::toTimeT() {
    return Clock::to_time_t(timepoint);
  };

}
