#ifndef CACHE_LRU_HPP_
#define CACHE_LRU_HPP_

#include "cache.hpp"
#include "cache_exception.hpp"
#include "time.hpp"

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
        throw CacheMiss <LRU <Key, Value> > ("Key not found in cache");
    return it->second;
}

template <typename Key, typename Value>
void LRU <Key, Value>::ThrowValue () {
    std::pair <Time, Key> trash = timeQueue_.top ();
    timeQueue_.pop ();
    hashTable_.erase (hashTable_.find (trash.second));
}

//  Специальный конструктор для CacheMiss от LRU<int, int>
template <>
CacheMiss <LRU <int, int> >::CacheMiss (const std::string& whatArg):
    runtime_error ("LOL"),
    what_ (whatArg),
    info_ ("LRU")
    {}

#endif