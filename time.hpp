#ifndef CACHE_TIME_HPP_
#define CACHE_TIME_HPP_

#include <iostream>
#include <chrono>

struct Time {
    std::chrono::steady_clock::time_point val = std::chrono::steady_clock::now();
};

bool operator < (Time lhs, Time rhs);

template <typename Key>
class CompareTime {
    public:
        bool operator () (std::pair <Time, Key> const& lhs, std::pair <Time, Key> const& rhs) {
            return lhs.first < rhs.first;
        }
};

#endif