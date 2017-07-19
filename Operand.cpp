//
// Created by kingh on 2017/07/18.
//

#include "Operand.h"

template class Operand<int8_t>;
template class Operand<int16_t>;
template class Operand<int32_t>;
template class Operand<float>;
template class Operand<double>;

template <class type> Operand<type>::Operand(): _data(std::to_string(static_cast<type>(0))){

}
template <class type> Operand<type>::Operand(type data):_data(std::to_string(data)) {

}

template <class type> Operand<type>::Operand(Operand<type> const &rhs): _data(rhs._data) {

}

template <class type> Operand<type> & Operand<type>::operator=(Operand<type> const & rhs) {
    if(this != &rhs) {
        this->_data = rhs.data;
    }
    return *this;
}

template <class type> Operand<type>::~Operand() {

}


template<class type> Operand<type>::Operand(std::string str): _data(std::to_string(static_cast<type>(stod(str)))) {

}


template <class type> void multiplicationRangeChecker(type a, type b) {
    type max;
    type positive_a;
    type positive_b;

    max = std::numeric_limits<type>::max();
    positive_a = (a < 0 ? -(a) : a);
    positive_b = (b < 0 ? -(b) : b);
    if(positive_a > max/positive_b) {
        if((a < 0) && (b < 0)) {
            throw Error::overFlow();
        }
        else if((a > 0) && (b > 0)) {
            throw Error::overFlow();
        }
        else {
            throw Error::underFlow();
        }
    }

}

template <class type> void additionRangeChecker(type a, type b) {
    type result;

    result = a + b;
    if((a < 0) == (b < 0)) {
        if((a < 0) && result > b) {
            throw Error::underFlow();
        }
        else if(result < a) {
            throw Error::overFlow();
        }
    }
}

template <class type> IOperand const * Operand<type>::operator+(IOperand const &rhs) const {
    type data1;
    type data2;
    IOperand const * value;
    operandFactory * obj;

    if(this->getPrecision() < rhs.getPrecision()) {
        return (rhs + *this);
    }
    data1 = static_cast<type>(stod(this->_data));
    data2 = static_cast<type>(stod(rhs.toString()));
    additionRangeChecker<type>(data1, data2);
    obj = new operandFactory();
    value = obj->createOperand(this->getType(), std::to_string(static_cast<type>(stod(this->_data)) + rhs._data));
    delete obj;
    return (value);
}

template <class type> IOperand const * Operand<type>::operator-(IOperand const &rhs) const {
    type data1;
    type data2;
    IOperand const * value;
    operandFactory * obj;

    if(this->getPrecision() < rhs.getPrecision()) {
        return (rhs - *this);
    }
    data1 = static_cast<type>(stod(this->_data));
    data2 = static_cast<type>(stod(rhs.toString()));
    additionRangeChecker<type>(data1, -(data2));
    obj = new operandFactory();
    value = obj->createOperand(this->getType(), std::to_string(data1 - data2));
    delete obj;
    return (value);
}

template <class type> IOperand const * Operand<type>::operator*(IOperand const &rhs) const {
    type data1;
    type data2;
    IOperand const * value;
    operandFactory * obj;

    if(this->getPrecision() < rhs.getPrecision()) {
        return (rhs * *this);
    }
    data1 = static_cast<type>(stod(this->_data));
    data2 = static_cast<type>(stod(rhs.toString()));
    multiplicationRangeChecker<type>(data1, data2);
    obj = new operandFactory();
    value = obj->createOperand(this->getType(), std::to_string(data1 * data2));
    delete obj;
    return (value);
}

template <class type> IOperand const * Operand<type>::operator/(IOperand const &rhs) const {
    double data1;
    double data2;
    eOperandType resType;
    IOperand const * value;
    operandFactory * obj;

    if(this->getPrecision() < rhs.getPrecision()) {
        return (rhs / *this);
    }
    data1 = stod(this->toString());
    data2 = stod(rhs.toString());
    if(data2 == 0) {
        throw Error::divisionByZero();
    }
    resType = (this->getPrecision() < rhs.getPrecision() ? rhs.getType() : this->getType());
    obj = new operandFactory();
    value = obj->createOperand(resType, std::to_string(data1 / data2));
    delete obj;
    return (value);
}

template <class type> IOperand const * Operand<type>::operator/(IOperand const &rhs) const {
    double data1;
    double data2;
    eOperandType resType;
    IOperand const * value;
    operandFactory * obj;

    if(data2 == 0) {
        throw Error::divisionByZero;
    }
    data1 = stol(this->toString());
    data2 = stol(rhs.toString());
    if(data2 == 0) {
        throw Error::divisionByZero();
    }
    resType = (this->getPrecision() < rhs.getPrecision() ? rhs.getType() : this->getType());
    obj = new operandFactory();
    value = obj->createOperand(resType, std::to_string(data1 % data2));
    delete obj;
    return (value);
}

template<class type> std::string const & Operand() const {
    return this->_data;
}

template<> int			Operand<int8_t>::getPrecision() const {
    return Int8;
}

template<> eOperandType	Operand<int8_t>::getType() const {
    return Int8;
}

template<> int			Operand<int16_t>::getPrecision() const {
    return Int16;
}

template<> eOperandType	Operand<int16_t>::getType( void ) const {
    return Int16;
}

template<> int			Operand<int32_t>::getPrecision( void ) const {
    return Int32;
}

template<> eOperandType	Operand<int32_t>::getType( void ) const	{
    return Int32;
}

template<> int			Operand<float>::getPrecision( void ) const {
    return Float;
}

template<> eOperandType	Operand<float>::getType( void ) const {
    return Float;
}

template<> int			Operand<double>::getPrecision( void ) const	{
    return Double;
}

template<> eOperandType	Operand<double>::getType( void ) const {
    return Double;
}
