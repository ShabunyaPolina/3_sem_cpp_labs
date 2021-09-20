#ifndef ITERATOR_H
#define ITERATOR_H

#include <iostream>
#include <algorithm>

template <class T> class BidirectionalList;

template <class T>
class Iterator {
public:
    virtual void First() = 0;
    virtual void Next() = 0;
    [[nodiscard]] virtual bool IsDone() const = 0;
    virtual T CurrentItem() const = 0;
};

// iterator for bidirectional list
template <class T>
class BidirectionalListIterator : public Iterator<T> {
public:
    explicit BidirectionalListIterator(const BidirectionalList<T>* list);
    virtual void First();
    virtual void Next();
    [[nodiscard]] virtual bool IsDone() const;
    virtual T CurrentItem() const;
private:
    const BidirectionalList<T>* _list;
    long _current;
};

template <class T>
BidirectionalListIterator<T>::BidirectionalListIterator
        (const BidirectionalList<T>* list)
        : _list(list), _current(_list->GetHead() - 1) {}

template <class T>
void BidirectionalListIterator<T>::First() {
    _current = _list->GetHead() - 1;
}

template <class T>
void BidirectionalListIterator<T>::Next() {
    ++_current;
}

template <class T>
bool BidirectionalListIterator<T>::IsDone() const {
    return _current >= _list->GetHead() + _list->Size() - 1;
}

template <class T>
T BidirectionalListIterator<T>::CurrentItem() const {
    try{
        if (IsDone())
            throw std::exception();
        return _list->Get(_current);
    }
    catch(const std::exception& e){
        std::cout << "iterator out of bounds\n";
    }
}


// reverse iterator for bidirectional list
template <class T>
class ReverseBidirectionalListIterator : public Iterator<T> {
public:
    explicit ReverseBidirectionalListIterator(const BidirectionalList<T>* list);
    virtual void First();
    virtual void Next();
    [[nodiscard]] virtual bool IsDone() const;
    virtual T CurrentItem() const;
private:
    const BidirectionalList<T>* _list;
    long _current;
};

template <class T>
ReverseBidirectionalListIterator<T>::ReverseBidirectionalListIterator
        (const BidirectionalList<T>* list)
        : _list(list), _current(_list->GetHead() + _list->Size() - 1) {}

template <class T>
void ReverseBidirectionalListIterator<T>::First() {
    _current = _list->GetHead() + _list->Size() - 2;
}

template <class T>
void ReverseBidirectionalListIterator<T>::Next() {
    --_current;
}

template <class T>
bool ReverseBidirectionalListIterator<T>::IsDone() const {
    return _current < 0;
}

template <class T>
T ReverseBidirectionalListIterator<T>::CurrentItem() const {
    try{
        if (IsDone())
            throw std::exception();
        return _list->Get(_current);
    }
    catch(const std::exception& e){
        std::cout << "iterator out of bounds\n";
    }
}

#endif  // ITERATOR_H
