#include "tester.hpp"

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