#include "Error.h"


char const * Error::divisionByZero::what(void) const _NOEXCEPT {
    return ("Error! division by zero");
}

char const * Error::emptyStack::what(void)   const _NOEXCEPT { 
    return ("Error! stack empty");
}

char const * Error::invalidValue::what(void) const _NOEXCEPT { 
    return ("Error! invalid value in instruction");
}

char const * Error::printNotInt8::what(void) const _NOEXCEPT { 
    return ("Error! unable to print, top value not 8-bit integer");
}

char const * Error::UnknownInstruction::what(void) const _NOEXCEPT { 
    return ("Error! invalid instruction");
}

char const * Error::UnknownOperation::what(void) const _NOEXCEPT { 
    return ("Error! invalid operation");
}

char const * Error::notEnoughValues::what(void) const _NOEXCEPT { 
    return ("Error! enough values in stack for operation");
}

char const * Error::assertionFalse::what(void) const _NOEXCEPT { 
    return ("Assert evaluated to false");
}

char const * Error::overflow::what(void) const _NOEXCEPT {
    return ("result overflow");
}

char const * Error::onderflow::what(void) const _NOEXCEPT {
    return ("result underflow");
}