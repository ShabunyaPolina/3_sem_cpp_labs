#ifndef ITERATOR_H
#define ITERATOR_H

//#include "bidirectional_list.h"
//#include "aggregate.h"

template <class T> class BidirectionalList;

template <class T>
class Iterator {
public:
    virtual void First() = 0;
    virtual void Next() = 0;
    [[nodiscard]] virtual bool IsDone() const = 0;
    virtual T CurrentItem() const = 0;
protected:
    //Iterator();
};

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
        : _list(list), _current(0) {}

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
    //if (IsDone())
    //   throw IteratorOutOfBounds;
    return _list->Get(_current);
}

#endif  // ITERATOR_H
