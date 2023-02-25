#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T>
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
private:
    std::vector<T> stackOfItems;
    unsigned int size_;
};

template <typename T>
Stack<T>::Stack() {
    size_ = 0;
}

template <typename T>
Stack<T>::~Stack() {

}

template <typename T>
bool Stack<T>::empty() const {
    return size_ == 0;
}

template <typename T>
size_t Stack<T>::size() const {
    return size_;
}

template <typename T>
void Stack<T>::push(const T& item) {
    stackOfItems.push_back(item);
    size_++;
}

template <typename T>
void Stack<T>::pop() {
    if (empty()) {
        throw std::underflow_error("Stack is empty");
    }
    else {
        stackOfItems.pop_back();
        size_--;
    }
}

template <typename T>
const T& Stack<T>::top() const {
    if (empty()) {
        throw std::underflow_error("Stack is empty");
    }
    return stackOfItems[size_-1];
}

#endif