#include "MagicalBag.hpp"

template<class T>
MagicalBag<T>::MagicalBag() {
    item_count_ = 0;
}

template<class T>
int MagicalBag<T>::getCurrentSize() const {
    return item_count_;
}

template<class T>
bool MagicalBag<T>::isEmpty() const {
    return (item_count_ == 0);
}

template<class T>
bool MagicalBag<T>::add(const T& newEntry) {
    bool hasRoom = (item_count_ < DEFAULT_CAPACITY);

    if (hasRoom) {
        for (int i = 0; i < item_count_; i++) {
            if (items_[i] == newEntry) {
                return false;
            }
        }

        items_[item_count_] = newEntry;
        item_count_++;
        return true;
    }

    return false;
}

template<class T>
bool MagicalBag<T>::remove(const T& anEntry) {
    int curr_index = 0;

    while (curr_index < item_count_) {
        if (items_[curr_index] == anEntry) {
            item_count_--;
            items_[curr_index] = items_[item_count_];
            return true;
        }

        curr_index++;
    }

    return false;
}

template<class T>
void MagicalBag<T>::clear() {
    item_count_ = 0;
}

template<class T>
bool MagicalBag<T>::contains(const T& target) const {
    int curr_index = 0;

    while (curr_index < item_count_) {
        if (items_[curr_index] == target) {
            return true;
        }

        curr_index++;
    }

    return false;
}