
#ifndef ABSTRACVM_OPERAND_H
#define ABSTRACVM_OPERAND_H


# ifndef OPERAND_H_DEFINED
    #  define OPERAND_H_DEFINED
    template<class type> class Operand;
    #  include "operandFactory.hpp"
# endif

#include "IOperand.h"
#include <string.h>
#include <limits>
#include "Error.h"


template<class type> class Operand : public IOperand {
    std::string _data;
public:
    Operand(void);
    Operand(type data);
    Operand(std::string str);
    Operand(Operand const &rhs);
    Operand & operator=(Operand const &);
    ~Operand();

    irtual int             getPrecision(void) const = 0; //Precision of the type of the instance
    virtual eOperandType    getType(void) const = 0; //Type of the instance

    IOperand const * operator+(IOperand const & rhs) const = 0; // Sum
    IOperand const * operator-(IOperand const & rhs) const = 0; // Difference
    IOperand const * operator*(IOperand const & rhs) const = 0; // Product
    IOperand const * operator/(IOperand const & rhs) const = 0; // Quotient
    IOperand const * operator%(IOperand const & rhs) const = 0; // Modulo
    std::string const & toString(void) const = 0; // String represantation of the instance
};


#endif //ABSTRACVM_OPERAND_H
