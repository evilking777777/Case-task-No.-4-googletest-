#pragma once
#include <deque>
#include <stdexcept>

template <typename T>
class Queue {
public:
    void push(const T& value) { data_.push_back(value); }
    T pop() {
        if (data_.empty()) throw std::out_of_range("queue is empty");
        T v = data_.front();
        data_.pop_front();
        return v;
    }
    bool empty() const { return data_.empty(); }
private:
    std::deque<T> data_;
};
