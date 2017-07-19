//
// Created by kingh on 2017/07/05.
//

#ifndef ABSTRACVM_IOPERAND_H
#define ABSTRACVM_IOPERAND_H

#include <iostream>

enum eOperandType {
    int8,
    int16,
    int32,
    Float,
    Double,
};


class IOperand {
public:

    virtual int             getPrecision(void) const = 0; //Precision of the type of the instance
    virtual eOperandType    getType(void) const = 0; //Type of the instance

    virtual IOperand const * operator+(IOperand const & rhs) const = 0; // Sum
    virtual IOperand const * operator-(IOperand const & rhs) const = 0; // Difference
    virtual IOperand const * operator*(IOperand const & rhs) const = 0; // Product
    virtual IOperand const * operator/(IOperand const & rhs) const = 0; // Quotient
    virtual IOperand const * operator%(IOperand const & rhs) const = 0; // Modulo

   // IOperand const * createOperand(eOperandType type, std::string const & value) const;

    virtual std::string const & toString(void) const = 0; // String represantation of the instance

    virtual ~IOperand(void) {};

};


#endif //ABSTRACVM_IOPERAND_H
