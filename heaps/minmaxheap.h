#ifndef ALGO_MINMAXHEAP_H
#define ALGO_MINMAXHEAP_H

#include <vector>
#include "heap.h"

template <typename T>
class MinMaxHeap : public Heap<T>
{
public:
    T extract_min();
    void insert(const T& val);
    bool empty() const;

private:
    void push_down_min(size_t it);
    void push_up_min(size_t it);
    void push_up_max(size_t it);
    bool is_min_level(size_t it) const;
    bool exists(size_t it) const;

    static size_t parent(size_t it) { return (it - 1) / 2; }
    static size_t leftchild(size_t it) { return it * 2 + 1; }
    static size_t rightchild(size_t it) { return it * 2 + 2; }

    std::vector<T> h;
};

template <typename T>
T MinMaxHeap<T>::extract_min()
{
    T res = h[0];
    h[0] = h.back();
    h.pop_back();
    if (!empty()) {
        push_down_min(0);
    }
    return res;
}

template <typename T>
void MinMaxHeap<T>::insert(const T &val)
{
    h.push_back(val);
    if (h.size() == 1) {
        return;
    }
    size_t it = h.size() - 1;
    bool is_min = is_min_level(it);
    if (is_min) {
        if (h[parent(it)] < h[it]) {
            std::swap(h[it], h[parent(it)]);
            push_up_max(parent(it));
        } else {
            push_up_min(it);
        }
    } else {
        if (h[parent(it)] > h[it]) {
            std::swap(h[it], h[parent(it)]);
            push_up_min(parent(it));
        } else {
            push_up_max(it);
        }
    }
}

template <typename T>
bool MinMaxHeap<T>::empty() const
{
    return h.empty();
}

template <typename T>
bool MinMaxHeap<T>::is_min_level(size_t it) const
{
    size_t depth = 0;
    while (it != 0) {
        it = parent(it);
        depth++;
    }
    return depth % 2 == 0;
}

template <typename T>
bool MinMaxHeap<T>::exists(size_t it) const
{
    return it < h.size();
}

template <typename T>
void MinMaxHeap<T>::push_down_min(size_t it)
{
    size_t lchild = leftchild(it);
    if (!exists(lchild)) {
        return;
    }
    size_t rchild = rightchild(it);
    size_t candidate = lchild;
    if (exists(rchild) && h[rchild] < h[candidate]) {
        candidate = rchild;
    }
    if (h[candidate] < h[it]) {
        std::swap(h[it], h[candidate]);
        push_down_min(it);
        return;
    }

    if (!exists(leftchild(lchild))) {
        return;
    }
    candidate = leftchild(lchild);
    size_t maybe = rightchild(lchild);
    if (exists(maybe) && h[maybe] < h[candidate]) {
        candidate = maybe;
    }
    maybe = leftchild(rchild);
    if (exists(maybe) && h[maybe] < h[candidate]) {
        candidate = maybe;
    }
    maybe = rightchild(rchild);
    if (exists(maybe) && h[maybe] < h[candidate]) {
        candidate = maybe;
    }
    if (h[candidate] < h[it]) {
        std::swap(h[it], h[candidate]);
        push_down_min(candidate);
        return;
    }
}

template <typename T>
void MinMaxHeap<T>::push_up_min(size_t it)
{
    if (it == 0 || parent(it) == 0) {
        return;
    }
    size_t pos = parent(parent(it));
    if (h[it] < h[pos]) {
        std::swap(h[pos], h[it]);
        push_up_min(pos);
    }
}

template <typename T>
void MinMaxHeap<T>::push_up_max(size_t it)
{
    if (it == 0 || parent(it) == 0) {
        return;
    }
    size_t pos = parent(parent(it));
    if (h[it] > h[pos]) {
        std::swap(h[pos], h[it]);
        push_up_max(pos);
    }
}

#endif //ALGO_MINMAXHEAP_H

