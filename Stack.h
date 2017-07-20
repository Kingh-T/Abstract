#ifndef ABSTRACVM_STACK_H
#define ABSTRACVM_STACK_H

# include <deque>
# include <stack>

template <class T> class Stack : public std::stack<T> {
    public:
        typedef typename std::deque<T>::iterator iterator;
        Stack();
        Stack(Stack const &rhs);
        ~Stack(void);
        Stack &operator=(Stack const &);
        Stack<T>::iterator begin(void);
        Stack<T>::iterator end(void);
};

#endif //ABSTRACVM_STACK_H
