#ifndef ALGO_BINARYHEAP_H
#define ALGO_BINARYHEAP_H

#include <vector>
#include "heap.h"

template <typename T>
class BinaryHeap : public Heap<T>
{
public:
    T extract_min();
    void insert(const T& val);
    bool empty() const;

private:
    void push_down(const T& val);
    void push_up(const T& val);
    bool exists(size_t it);

    static size_t parent(size_t it) { return (it - 1) / 2; }
    static size_t leftchild(size_t it) { return it * 2 + 1; }
    static size_t rightchild(size_t it) { return it * 2 + 2; }

    std::vector<T> h;
};

template <typename T>
T BinaryHeap<T>::extract_min()
{
    T res = h[0];
    T unplaced = h.back();
    h.pop_back();
    if (!empty()) {
        push_down(unplaced);
    }
    return res;
}

template <typename T>
void BinaryHeap<T>::insert(const T &val)
{
    h.push_back(T());
    push_up(val);
}

template <typename T>
bool BinaryHeap<T>::empty() const
{
    return h.empty();
}

template <typename T>
bool BinaryHeap<T>::exists(size_t it)
{
    return it < h.size();
}

template <typename T>
void BinaryHeap<T>::push_down(const T& val)
{
    size_t it = 0;
    while (exists(leftchild(it))) {
        size_t candidate = leftchild(it);
        if (exists(rightchild(it)) && h[candidate] > h[rightchild(it)]) {
            candidate = rightchild(it);
        }
        if (val > h[candidate]) {
            h[it] = h[candidate];
            it = candidate;
        } else {
            break;
        }
    }
    h[it] = val;
}


template <typename T>
void BinaryHeap<T>::push_up(const T& val)
{
    size_t it = h.size() - 1;
    while (it > 0 && h[parent(it)] > val) {
        h[it] = h[parent(it)];
        it = parent(it);
    }
    h[it] = val;
}

#endif //ALGO_BINARYHEAP_H
