#ifndef CACHE_EXCEPTION_HPP_
#define CACHE_EXCEPTION_HPP_

#include <sstream>
#include <string>

#include "lru.hpp"

template <class CacheType>
class CacheMiss : public std::runtime_error {
    public:
        CacheMiss (const std::string& whatArg);
        std::string stringWhat() noexcept {
            std::ostringstream ostr;
            ostr << info_ << ':' << std::endl << what_;
            std::string ans = ostr.str ();
            return ans;
        }
    private:
        const std::string what_ = {};
        const std::string info_ = {};      
};

#endif