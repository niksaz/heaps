#ifndef ALGO_PRIORITYHEAP_H
#define ALGO_PRIORITYHEAP_H

#include <vector>
#include <queue>
#include <functional>
#include "heap.h"

template <typename T>
class PriorityHeap : public Heap<T>
{
public:
    T extract_min();
    void insert(const T& val);
    bool empty() const;

private:
    std::priority_queue<T, std::vector<T>, std::greater<T>> q;
};

template <typename T>
T PriorityHeap<T>::extract_min()
{
    T res = q.top();
    q.pop();
    return res;
}

template <typename T>
void PriorityHeap<T>::insert(const T &val)
{
    q.push(val);
}

template <typename T>
bool PriorityHeap<T>::empty() const
{
    return q.empty();
}

#endif //ALGO_PRIORITYHEAP_H
