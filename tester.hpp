#ifndef CACHE_TESTER_HPP_
#define CACHE_TESTER_HPP_

#include <queue>

#include "time.hpp"

template <typename Key>
std::ostream& operator << 
(std::ostream& stream, std::priority_queue <std::pair <Time, Key>,
 std::vector <std::pair <Time, Key> >, CompareTime <Key> > q) {
    while (!q.empty()) {
        stream << q.top().second << ' ';
        q.pop ();
    }
    return stream;
}

#endif