#pragma once
#include <vector>
#include <algorithm>
#include <stdexcept>

template <typename T>
class Heap {
public:
    void push(const T& value) {
        data_.push_back(value);
        std::push_heap(data_.begin(), data_.end());
    }
    T pop() {
        if (data_.empty()) throw std::out_of_range("heap is empty");
        std::pop_heap(data_.begin(), data_.end());
        T v = data_.back();
        data_.pop_back();
        return v;
    }
private:
    std::vector<T> data_;
};
