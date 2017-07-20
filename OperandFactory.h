#ifndef ABSTRACVM_OPERANDFACTORY_H
#define ABSTRACVM_OPERANDFACTORY_H

#include "IOperand.h"
#include <iostream>
#include <cerrno>

#ifndef ABSTRACVM_OPERANDFACTORY_H_DEFINED
    # define ABSTRACTCVM_OPERANDFACTORY_H_DEFINED
    class OperandFactory;
    #include "Operand.h"
#endif

class OperandFactory {
    IOperand const * createInt8(std::string const & value) const;
    IOperand const * createInt16(std::string const & value) const;
    IOperand const * createInt32(std::string const & value) const;
    IOperand const * createFloat(std::string const & value) const;
    IOperand const * createDouble(std::string const & value) const;

public:
    typedef IOperand const * (OperandFactory::*IOPFP)(std::string const &) const;
    OperandFactory();
    OperandFactory(OperandFactory const & rhs);
    ~OperandFactory();
    OperandFactory &operator=(OperandFactory const &);

    IOperand const * createOperand(eOperandType type, std::string const & value) const;
};


#endif //ABSTRACVM_OPERANDFACTORY_H