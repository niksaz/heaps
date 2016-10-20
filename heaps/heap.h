#ifndef ALGO_HEAP_H
#define ALGO_HEAP_H

template <typename T>
class Heap
{
public:
    virtual T extract_min() = 0;
    virtual void insert(const T& val) = 0;
    virtual bool empty() const = 0;
    virtual ~Heap<T>() = default;
};

#endif //ALGO_HEAP_H
