#include "cache_exception.hpp"

CacheMiss::CacheMiss (const std::string& whatArg):
    what_ (whatArg),
    info_ ("LRU")
    {}

