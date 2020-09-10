#include "time.hpp"

bool operator < (Time lhs, Time rhs) {
    auto dur = rhs.val - lhs.val;
    int nanosecTime = std::chrono::duration_cast <std::chrono::nanoseconds> (dur).count ();
    return nanosecTime > 0;
}