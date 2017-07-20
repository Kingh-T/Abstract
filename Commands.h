//
// Created by kingh on 2017/07/20.
//

#ifndef ABSTRACVM_COMMANDS_H
#define ABSTRACVM_COMMANDS_H

# include "Stack.h"
# include "OperandFactory.h"
# include "Error.h"
# include <string>
# include <iostream>
# include <sstream>
# include <vector>
# include <algorithm>


class Commands {
    IterStack<IOperand const*> stack;
    OperandFactory factory;
    public:
        bool verbose;
        bool contOnError;

        Commands();
        Commands(Commands const & rhs);
        Commands &operator=(Commands const &);
        ~Commands();

        bool call(std::string cmd);
        void push(std::string val);
        void pop();
        void dump();
        void print();
};


#endif //ABSTRACVM_COMMANDS_H
