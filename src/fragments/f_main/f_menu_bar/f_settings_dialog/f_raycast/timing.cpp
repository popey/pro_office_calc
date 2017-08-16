#include <chrono>
#include "fragments/f_main/f_menu_bar/f_settings_dialog/f_raycast/timing.hpp"


namespace chrono = std::chrono;
using std::function;


inline static unsigned long getTime() {
  return chrono::high_resolution_clock::now().time_since_epoch() / chrono::milliseconds(1);
}

TRandomIntervals::TRandomIntervals(unsigned long min, unsigned long max) {
  //std::random_device rd;

  m_randEngine.seed(1/*rd()*/);
  m_distribution = std::uniform_real_distribution<>(min, max);

  calcDueTime();
}

bool TRandomIntervals::doIfReady(function<void()> fn) {
  double t = getTime();

  if (t >= m_dueTime) {
    fn();
    calcDueTime();

    return true;
  }

  return false;
}

void TRandomIntervals::calcDueTime() {
  m_dueTime = getTime() + m_distribution(m_randEngine);
}
