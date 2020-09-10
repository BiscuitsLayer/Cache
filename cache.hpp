#ifndef CACHE_CACHE_HPP_
#define CACHE_CACHE_HPP_

#include <iostream>
#include <string>

template <typename Key, typename Value>
class Cache {
    public:
        Cache ():
            curSize_ (0)
            {}
    //  нет стандартных PutValue, GetValue, ThrowValue, т.к. тип хранения 
    //  варьируется в зависимости от кэша
        virtual void PutValue (std::pair <Key, Value> p) = 0;
        virtual Value GetValue (const Key& key) = 0;
        virtual void ThrowValue () = 0;
    //  чтобы в контейнере не вызвать конструктор базового класса (предотвращение утечки памяти)
    //  virtual ~Cache ();
    protected:
        const int curSize_ = 0;
};

#endif