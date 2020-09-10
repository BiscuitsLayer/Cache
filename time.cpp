#include "time.hpp"

bool operator < (Time lhs, Time rhs) {
    auto dur = rhs.val - lhs.val;
    int nanosecTime = std::chrono::duration_cast <std::chrono::nanoseconds> (dur).count ();
    return nanosecTime > 0;
}

template <typename Key>
bool CompareTime <Key>::operator () (std::pair <Time, Key> const& lhs, std::pair <Time, Key> const& rhs) {
    return lhs.first < rhs.first;
}