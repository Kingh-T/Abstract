//
// Created by kingh on 2017/07/18.
//

#ifndef ABSTRACVM_ERROR_H
#define ABSTRACVM_ERROR_H

#include <exception>

struct AbstractVM {
    struct divisionByZero : public std::exception {
        char const * what( void ) const _NOEXCEPT;
    };

    struct emptyStack   : public std::exception {
        char const * what( void ) const _NOEXCEPT;
    };

    struct invalidValue : public std::exception {
        char const * what( void ) const _NOEXCEPT;
    };

    struct printNotInt8 : public std::exception {
        char const * what( void ) const _NOEXCEPT;
    };

    struct unknownInstruction : public std::exception {
        char const * what( void ) const _NOEXCEPT;
    };

    struct unknownOperation : public std::exception {
        char const * what( void ) const _NOEXCEPT;
    };

    struct notEnoughValues : public std::exception {
        char const * what( void ) const _NOEXCEPT;
    };

    struct assertionFalse : public std::exception {
        char const * what( void ) const _NOEXCEPT;
    };

    struct overflow : public std::exception {
        char const * what( void ) const _NOEXCEPT;
    };

    struct underflow : public std::exception {
        char const * what( void ) const _NOEXCEPT;
    };
};


#endif //ABSTRACVM_ERROR_H
