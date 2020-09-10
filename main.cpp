#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <chrono>
#include <iterator>

static const int MAX_CACHE_SIZE = 1e3;

//  Мои библиотеки

#include "time.hpp"
#include "tester.hpp"
#include "cache_exception.hpp"

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

template <typename Key, typename Value>
class LRU : public Cache <Key, Value> {
    public:
        virtual void PutValue (std::pair <Key, Value> p) override;
        virtual Value GetValue (const Key& key) override;
        virtual void ThrowValue () override;
    //  временно всё public (для дебага)
    //  private:
        std::unordered_map <Key, Value> hashTable_ = {};
        std::priority_queue <std::pair <Time, Key>, 
        std::vector <std::pair <Time, Key> >, CompareTime <Key> > timeQueue_ = {};
    //    std::priority_queue <std::pair <Time, Key> > timeQueue_ = {};
};

template <typename Key, typename Value>
void LRU <Key, Value>::PutValue (std::pair <Key, Value> p) {
    if (this->curSize_ == MAX_CACHE_SIZE) {
        ThrowValue ();
    }
    hashTable_[p.first] = p.second;
    timeQueue_.push ({ Time(), p.second });
}

template <typename Key, typename Value>
Value LRU <Key, Value>::GetValue (const Key& key) {
    auto it = hashTable_.find (key);
    if (it == hashTable_.end ())
        throw CacheMiss ("Key not found in LRU Cache");
    return it->second;
}

template <typename Key, typename Value>
void LRU <Key, Value>::ThrowValue () {
    std::pair <Time, Key> trash = timeQueue_.top ();
    timeQueue_.pop ();
    hashTable_.erase (hashTable_.find (trash.second));
}

int main () {
    try {
        LRU <int, int> lru = {};
        lru.PutValue ({1, 3});
        lru.PutValue ({2, 4});
        lru.PutValue ({2, 6});
        lru.PutValue ({2, 5});
        std::cout << lru.timeQueue_ << std::endl;
        std::cout << lru.GetValue (2) << std::endl;
        std::cout << lru.GetValue (3) << std::endl;
    } catch (CacheMiss& ex) {
        std::cerr << "Expection caught: " << ex.what() << std::endl;
    }
    return 0;
}