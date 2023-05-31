//
// Created by leonard04 on 5/30/23.
//

#ifndef FUNCTIONS_MULTIPLY_H
#define FUNCTIONS_MULTIPLY_H


#include "../function.h"

// Multiplies two functions
class MultiplyFunction : public Function{
    Function* f;
    Function* g;

public:
    double evaluate(double x) const override{
        return (*f)(x) * (*g)(x);
    }

    virtual std::string to_string(Function* func) const = 0;
    virtual Function& differentiate() const = 0;

    virtual Function* clone() const = 0;

};

class MultiplyScalar{

};


#endif //FUNCTIONS_MULTIPLY_H
