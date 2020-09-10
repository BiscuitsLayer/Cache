#ifndef CACHE_EXCEPTION_HPP_
#define CACHE_EXCEPTION_HPP_

#include <iostream>
#include <sstream>
#include <string>

class CacheMiss : public std::exception {
    public:
        CacheMiss (const std::string& whatArg);
        const char* what() noexcept {
            std::ostringstream ostr;
            ostr << info_ << ":\n" << what_;
            std::cout << ostr.str().c_str() << std::endl;
            return ostr.str().c_str();
        }
    private:
        const std::string what_ = {};
        const std::string info_ = {};      
};

#endif