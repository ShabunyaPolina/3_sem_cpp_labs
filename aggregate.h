#ifndef AGGREGATE_H
#define AGGREGATE_H

#include <iostream>
#include <initializer_list>
#include <algorithm>

#include "iterator.h"

template <class T>
class Aggregate {
public:
    // фабричный метод, связывает две иерархии: списков и итераторов
    virtual Iterator<T>* CreateIterator() const = 0;
};

template <class T>
class BidirectionalList : public Aggregate<T>{
public:
    BidirectionalList();
    explicit BidirectionalList(int capacity);
    BidirectionalList(const std::initializer_list<T>& list);
    BidirectionalList(const BidirectionalList<T>& list);
    BidirectionalList(BidirectionalList<T>&& list) noexcept;
    ~BidirectionalList();
    void Swap(BidirectionalList<T>& list1, BidirectionalList<T>& list2);
    [[nodiscard]] bool IsEmpty() const noexcept;
    [[nodiscard]] int Size() const noexcept;
    void Clear();
    T& Front() const;
    T& Back() const;
    void PushFront(const T& value);
    void PushBack(const T& value);
    void PopFront();
    void PopBack();
    void Resize();
    void Resize(int new_capacity);
    BidirectionalList<T> operator+(const BidirectionalList<T>& another_list);
    BidirectionalList<T>& operator+=(const BidirectionalList<T>& another_list);
    BidirectionalList<T>& operator=(const BidirectionalList<T>& another_list);
    BidirectionalList<T>& operator=(BidirectionalList<T>&& another_list) noexcept;
    bool operator==(const BidirectionalList<T>& another_list);
    bool operator!=(const BidirectionalList<T>& another_list);
    void Show();
    friend std::ostream& operator<< (std::ostream &out, const BidirectionalList<T>& list) {
//        for(int i = list.head_ - 1; i < list.head_ + list.size_ - 1; ++i) {
//            out << list.list_ptr_[i] << ' ';
//        }
        Iterator<T>* i = list.CreateIterator();
        for(i->First(); !i->IsDone(); i->Next()) {
            out << i->CurrentItem() << ' ';
        }
        return out;
    }

    T& Get(long index) const;
    Iterator<T>* CreateIterator() const override;
    [[nodiscard]] int GetHead() const;

private:
    const int INITIAL_CAPACITY {10};
    const float RESIZE_FACTOR {1.5};
    int capacity_;
    int head_;
    int size_;
    T* list_ptr_;
};

// default constructor
template <class T>
BidirectionalList<T>::BidirectionalList() : capacity_(INITIAL_CAPACITY),
                                            head_(capacity_ / 2),
                                            size_(0),
                                            list_ptr_(new T[INITIAL_CAPACITY]) {
    std::cout << "-> default constructor\n";
}

// constructor with certain capacity
template <class T>
BidirectionalList<T>::BidirectionalList(int capacity) : capacity_(capacity),
                                                        head_(capacity / 2),
                                                        size_(0),
                                                        list_ptr_(new T[capacity]) {
    std::cout << "-> constructor with certain capacity\n";
}

// constructor by std::initializer_list
template <class T>
BidirectionalList<T>::BidirectionalList(const std::initializer_list<T>& list)
        : capacity_(list.size() * RESIZE_FACTOR),
          size_(list.size()),
          head_((capacity_ - list.size()) / 2 + 1),
          list_ptr_(new T[capacity_]) {
    std::cout << "-> constructor by std::initializer_list\n";
    std::uninitialized_copy(list.begin(), list.begin() + list.size(), list_ptr_ + head_ - 1);
}

// copy constructor
template <class T>
BidirectionalList<T>::BidirectionalList(const BidirectionalList<T>& list)
        : capacity_(list.capacity_),
          head_(list.head_),
          size_(list.size_),
          list_ptr_(new T[list.capacity_]){
    std::cout << "-> copy constructor\n";
    std::uninitialized_copy(list.list_ptr_, list.list_ptr_ + list.capacity_, list_ptr_);
}

// move constructor
template <class T>
BidirectionalList<T>::BidirectionalList(BidirectionalList<T> &&list) noexcept
        : capacity_(0),
          head_(0),
          size_(0),
          list_ptr_(nullptr) {
    std::cout << "-> move constructor\n";
    *this = std::move(list);
}

// destructor
template <class T>
BidirectionalList<T>::~BidirectionalList() { delete[] list_ptr_; }

// swaps two lists
template <class T>
void BidirectionalList<T>::Swap(BidirectionalList<T>& list1, BidirectionalList<T>& list2) {
    std::cout << "-> swap\n";
    BidirectionalList<T> tmp = std::move(list1);
    list1 = std::move(list2);
    list2 = std::move(tmp);
}

// checks if the list is empty
template <class T>
bool BidirectionalList<T>::IsEmpty() const noexcept { return !size_; }

// returns current number of elements
template <class T>
int BidirectionalList<T>::Size() const noexcept { return size_; }

// removes all elements of the list
template <class T>
void BidirectionalList<T>::Clear() {
    if(size_ == 0) return;
    while(size_ != 0) {
        PopBack();
    }
    head_ = capacity_ / 2;
}

// returns the first element of the list
template <class T>
T& BidirectionalList<T>::Front() const {
    try{
        if(size_ == 0)
            throw std::exception();
    }
    catch(const std::exception& e){
        std::cout << "no elements ";
    }
    return list_ptr_[head_ - 1];
}

// returns the last element of the list
template <class T>
T& BidirectionalList<T>::Back() const {
    try{
        if(size_ == 0)
            throw std::exception();
    }
    catch(const std::exception& e){
        std::cout << "no elements ";
    }
    return list_ptr_[head_ + size_ - 2];
}

// insert an element at the top of the list
template <class T>
void BidirectionalList<T>::PushFront(const T& value) {
    if(head_ == 1)
        Resize();
    if(size_ != 0)
        --head_;
    list_ptr_[head_ - 1] = value;
    ++size_;
}

// removes one element from the top of the list
template <class T>
void BidirectionalList<T>::PopFront() {
    try{
        if(size_ == 0)
            throw std::exception();
        ++head_;
        --size_;
    }
    catch(const std::exception& e){
        std::cout << "no elements\n";
    }
}

// removes one element from the end of the list
template <class T>
void BidirectionalList<T>::PopBack() {
    try{
        if(size_ == 0)
            throw std::exception();
        --size_;
    }
    catch(const std::exception& e){
        std::cout << "no elements\n";
    }
}

// inserts an element at the end of the list
template <class T>
void BidirectionalList<T>::PushBack(const T& value) {
    if(head_ + size_ - 1 == capacity_)
        Resize();
    list_ptr_[head_ + size_ - 1] = value;
    ++size_;
}

// increases the current capacity
template <class T>
void BidirectionalList<T>::Resize() {
    Resize(capacity_ * RESIZE_FACTOR);
}

// changes the current capacity into given value
template <class T>
void BidirectionalList<T>::Resize(int new_capacity) {
    if(new_capacity > capacity_) {
        BidirectionalList<T> tmp (new_capacity);
        tmp.head_ = (new_capacity -  capacity_) / 2 + head_;
        tmp.size_ = size_;
        std::uninitialized_copy(list_ptr_, list_ptr_ + capacity_, tmp.list_ptr_ + (new_capacity -  capacity_) / 2);
        Swap(*this, tmp);
    }
}

// '+' operator overloading
template <class T>
BidirectionalList<T> BidirectionalList<T>::operator+
        (const BidirectionalList<T>& another_list) {
    int new_capacity = (size_ + another_list.size_) * RESIZE_FACTOR;
    BidirectionalList<T> sum(new_capacity);
    sum += *this;
    sum += another_list;
    return sum;
}

// '+=' operator overloading
template <class T>
BidirectionalList<T>& BidirectionalList<T>::operator+=
        (const BidirectionalList<T>& another_list) {
    capacity_ = (size_ + another_list.size_) * RESIZE_FACTOR;
    BidirectionalList<T> tmp(capacity_);
    tmp.size_ = this->size_ + another_list.size_;
    tmp.head_ = (tmp.capacity_ - tmp.size_) / 2 + 1;
    std::uninitialized_copy(list_ptr_ + head_ - 1,
                            list_ptr_ + head_ + size_ - 1,
                            tmp.list_ptr_ + tmp.head_ - 1);
    std::uninitialized_copy(another_list.list_ptr_ + another_list.head_ - 1,
                            another_list.list_ptr_ + another_list.head_ + another_list.size_ - 1,
                            tmp.list_ptr_ + tmp.head_ + size_ - 1);
    *this = std::move(tmp);
    return *this;
}

// copy assignment operator overloading
template <class T>
BidirectionalList<T>& BidirectionalList<T>::operator=(const BidirectionalList<T>& another_list) {
    if (this != &another_list) {
        std::cout << "-> copy=\n";
        BidirectionalList<T> tmp{another_list};
        Swap(tmp, *this);
    }
    return *this;
}

// move assignment operator overloading
template <class T>
BidirectionalList<T>& BidirectionalList<T>::operator=(BidirectionalList<T>&& another_list) noexcept {
    std::cout << "-> move=\n";
    delete[] list_ptr_;
    capacity_ = another_list.capacity_;
    head_ = another_list.head_;
    size_ = another_list.size_;
    list_ptr_ = another_list.list_ptr_;
    another_list.capacity_ = 0;
    another_list.head_ = 0;
    another_list.size_ = 0;
    another_list.list_ptr_ = nullptr;
    return *this;
}

// '==' operator overloading
template <class T>
bool BidirectionalList<T>::operator==(const BidirectionalList<T>& another_list) {
    if(size_ != another_list.size_)
        return false;
    int counter = size_;
    int i = head_ - 1;
    int j = another_list.head_ - 1;
    while(--counter >= 0) {
        if(this->list_ptr_[i] != another_list.list_ptr_[j])
            return false;
    }
    return true;
}

// '!=' operator overloading
template <class T>
bool BidirectionalList<T>::operator!=(const BidirectionalList<T>& another_list) {
    bool tmp = (*this == another_list);
    return !tmp;
}

// shows info about the list
template <class T>
void BidirectionalList<T>::Show() {
    std::cout << "capacity: " << capacity_;
    std::cout << "\nsize: " << size_;//Size();
    std::cout << "\nhead: " << head_;
    IsEmpty() ? std::cout << "\nIsEmpty\n" : std::cout << "\nIsNotEmpty\n";
    std::cout << *this;
    std::cout << "\nfirst elem: " << Front()
              << "\nlast elem:  " << Back();
    std::cout << "\n--------------------------\n";
}

template <class T>
T& BidirectionalList<T>::Get(long index) const {
    return list_ptr_[index];
}

template <class T>
Iterator<T>* BidirectionalList<T>::CreateIterator() const {
    return new BidirectionalListIterator<T>(this);
}

template <class T>
int BidirectionalList<T>::GetHead() const{
    return head_;
}

#endif  // AGGREGATE_H
