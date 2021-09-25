#ifndef VISITOR_H
#define VISITOR_H

#include <string>

template <class T>
class Visitor {
public:
    virtual void Visit(T elem) = 0;
};

// visitor for elements of string type
template <class T>
class VisitorToString : public Visitor<T> {
public:
    void Visit(int elem) override;
    [[nodiscard]] std::string GetString() const;
private:
    std::string str;
};

template <class T>
void VisitorToString<T>::Visit(int elem) {
    str += std::to_string(elem) + ' ';
}

template <class T>
std::string VisitorToString<T>::GetString() const {
    return str;
}

// visitor for elements of integer type
template <class T>
class SumVisitor : Visitor<T> {
public:
    void Visit(int elem) override;
    [[nodiscard]] int GetSum() const;
private:
    int sum {0};
};

template <class T>
void SumVisitor<T>::Visit(int elem) {
    sum += elem;
}

template <class T>
int SumVisitor<T>::GetSum() const {
    return sum;
}

#endif  // VISITOR_H
