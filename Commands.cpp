#include "Commands.h"

Commands::Commands(): verbose(false), contOnError(false) {
}

Commands::Commands(Commands const & rhs): verbose(rhs.verbose), contOnError(rhs.contOnError) {
}

Commands::~Commands() {
    IterStack<IOperand const*>::iterator i;
    IterStack<IOperand const*>::iterator end = this->stack.end();
    for (i = this->stack.begin(); i != end; i++) {
        delete *i;
    }
}
Commands & Commands::operator=(Commands const & rhs) {
    static_cast<void>(rhs);
    return *this;
}

bool Commands::call(std::string cmd) {
    static const std::vector<std::string> ops = { "add", "sub", "mul", "div", "mod" };
    static std::string names[] = { "int8", "int16", "int32", "float", "double" };
    try {
        if (cmd.find(';') != std::string::npos) {
            cmd.erase(cmd.find(';'), std::string::npos);
        }
        if (cmd.find_first_not_of(" \t") != 0) {
            cmd.erase(0, cmd.find_first_not_of(" \t"));
        }
        while (cmd.size() != 0 && cmd.find_last_of(" \t") == cmd.size()-1) {
            cmd.pop_back();
        }
        if (cmd.size() == 0) {
            return true;
        }
        else if (cmd == "exit") {
            return false;
        }
        else if (cmd == "pop") {
            this->pop();
        }
        else if (cmd == "dump") {
            this->dump();
        }
        else if (cmd == "print") {
            this->print();
        }
        else if (cmd.substr(0,5) == "push ") {
            this->push(cmd.substr(5,std::string::npos));
        }
        else if (std::find(ops.begin(), ops.end(), cmd) != ops.end()) {
            if (this->stack.size() < 2) {
                throw Error::notEnoughValues();
            }
            IOperand const * rhs = this->stack.top();
            this->stack.pop();
            IOperand const * lhs = this->stack.top();
            this->stack.pop();
            IOperand const * created = nullptr;
            if (this->verbose) {
                std::cout << "Operation: " << cmd << ' ' << names[lhs->getType()] << '(' << lhs->toString() << ") "
                          << names[rhs->getType()] << '(' << rhs->toString() << ')' << std::endl;
            }
            if (cmd == "add") {
                created = *lhs + *rhs;
            }
            else if (cmd == "sub") {
                created = *lhs - *rhs;
            }
            else if (cmd == "mul") {
                created = *lhs * *rhs;
            }
            else if (cmd == "div") {
                created = *lhs / *rhs;
            }
            else if (cmd == "mod"){

            } created = *lhs % *rhs;
            else {
                throw Error::unknownOperation();
            }
            this->stack.push(created);
            delete lhs;
            delete rhs;
        }
        else if (cmd.substr(0,7) == "assert ") {
            this->push(cmd.substr(7,std::string::npos));
            IOperand const * lhs = this->stack.top();
            this->stack.pop();
            IOperand const * rhs = this->stack.top();
            if (lhs->getType() != rhs->getType() || lhs->toString() != rhs->toString())
                throw Error::assertionFalse();
            else if (this->verbose) {
                std::cout << "Assert passed: " << lhs->toString() << " == " << rhs->toString() << std::endl;
            }
            delete lhs;
        }
        else {
            if (this->verbose) std::cout << "Error: Unknown Command: " << cmd << std::endl;
            else throw Error::unknownCommand();
        }
        return true;
    } catch (std::exception & e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return this->contOnError;
    }
}

void Commands::push(std::string val) {
    static std::string names[] = { "int8", "int16", "int32", "float", "double" };
    if (val.size() < 4) {
        throw Error::InvalidValue();
    }
    if (val.find('(') == std::string::npos) {
        throw Error::InvalidValue();
    }
    if (val.back() != ')') {
        throw Error::InvalidValue();
    }
    val.pop_back();
    unsigned int open_p = val.find('(');
    std::string type_string = val.substr(0, open_p);
    val.erase(val.begin(), val.begin()+open_p+1);
   /* if (this->verbose) {
        std::cout << "Pushing " << type_string << '(' << val << ')' << std::endl;
    }*/
    for (int i = Int8; i <= Double; i++ ) {
        if (type_string == names[i]) {
            this->stack.push(factory.createOperand(static_cast<eOperandType>(i), val));
            return;
        }
    }
    throw Error::invalidValue();
}

void Commands::pop(void) {
    if (this->stack.size() < 1) {
        throw Error::emptyStack();
    }
    delete this->stack.top();
    this->stack.pop();
}

void Commands::dump(void) {
    IterStack<IOperand const*>::iterator i;
    IterStack<IOperand const*>::iterator end = this->stack.end();
    for (i = this->stack.begin(); i != end; i++) {
        std::cout << (*i)->toString() << std::endl;
    }
}

void Commands::print(void) {
    if (this->stack.size() < 1) {
        throw Error::printNotInt8();
    }
    IOperand const * top = this->stack.top();
    if (top->getType() != Int8) {
        throw Error::printNotInt8();
    }
    char c = std::stoi(top->toString());
    if (c > 32 && c < 127) {
        std::cout << c << '\n';
    }
    else {
        std::cout << "Non-displayable character (" << std::stoi(top->toString()) << ')' << std::endl;
    }
}




