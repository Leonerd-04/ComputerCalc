//
// Created by leonard04 on 5/30/23.
//

#ifndef FUNCTIONS_MULTIPLY_H
#define FUNCTIONS_MULTIPLY_H


#include "../function.h"
#include "addition.h"

class Multiply;

Multiply& operator*(const Function& f, const Function& g);

// Multiplies two functions
class Multiply : public Function{
    Function& f;
    Function& g;

public:
    Multiply(const Function& f, const Function& g) : f(*f.clone()), g(*g.clone()){}

    double evaluate(double x) const override{
        return f(x) * g(x);
    }

    std::string to_string(Function* func) const override {
        return "(" + f.to_string() + ")(" + g.to_string() +  ")";
    }

    // Product rule: (fg)' = f'g + fg'
    Addition& differentiate() const override{
        return f.differentiate() * g  +  f * g.differentiate();
    }

    Multiply(const Multiply& other): f(*other.f.clone()), g(*other.g.clone()){}

    Multiply* clone() const override {
        return new Multiply(*this);
    }

};

Multiply& operator*(const Function& f, const Function& g){
    return *new Multiply(f, g);
}

#endif //FUNCTIONS_MULTIPLY_H
