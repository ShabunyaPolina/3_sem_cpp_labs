#ifndef AGGREGATE_H
#define AGGREGATE_H

#include "iterator.h"

template <class T>
class Aggregate {
public:
    virtual Iterator<T>* CreateIterator() const = 0;  // factory method
                                                      // links two hierarchies:
                                                      // containers and iterators
    virtual Iterator<T>* CreateReverseIterator() const = 0;
};

#endif  // AGGREGATE_H
