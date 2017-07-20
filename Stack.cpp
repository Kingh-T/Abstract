#include "Stack.h"

template <class T> Stack<T>::Stack() {}

template <class T> Stack<T>::Stack(Stack<T> const & obj) {
    *this = obj;
}

template <class T> Stack<T>::~Stack() {}
template <class T> Stack<T> & Stack<T>::operator=(Stack<T> const & rhs) {
    this->std::stack<T>::operator=(rhs);
    return *this;
}

template <class T> typename Stack<T>::iterator Stack<T>::begin() {
    return this->c.begin();
}
template <class T> typename Stack<T>::iterator Stack<T>::end() {
    return this->c.end();
}