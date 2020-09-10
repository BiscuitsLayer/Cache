#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <chrono>
#include <iterator>
#include <typeinfo>

static const int MAX_CACHE_SIZE = 1e3;

//  Мои библиотеки

#include "lru.hpp"
#include "time.hpp"
#include "tester.hpp"
#include "cache_exception.hpp"

#define GET(cache, key)                                             \
try {                                                               \
    std::cout << cache.GetValue (key) << std::endl;                 \
} catch (CacheMiss <decltype (cache)>& ex) {                        \
    std::cerr << "Expection caught: " << ex.stringWhat () << std::endl;   \
}

int main () {
    LRU <int, int> lru = {};
    lru.PutValue ({1, 3});
    lru.PutValue ({2, 4});
    lru.PutValue ({2, 6});
    lru.PutValue ({2, 5});
    std::cout << lru.timeQueue_ << std::endl;
    GET (lru, 2);
    GET (lru, 3)
    return 0;
}