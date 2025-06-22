#ifndef MAGICALBAG_H
#define MAGICALBAG_H

template<class T>
class MagicalBag {
    
    public:
        MagicalBag();
        int getCurrentSize() const;
        bool isEmpty() const;
        bool add(const T& newEntry);
        bool remove(const T& anEntry);
        void clear();
        bool contains(const T& target) const;


    protected:
        static const int DEFAULT_CAPACITY = 100;
        T items_[DEFAULT_CAPACITY];
        int item_count_;
};

#include "MagicalBag.cpp"
#endif