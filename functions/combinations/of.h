//
// Created by leonard04 on 5/30/23.
//

#ifndef FUNCTIONS_OF_H
#define FUNCTIONS_OF_H


#include "../function.h"
#include "multiply.h"

// Nested functions
// Represents outer of inner
class Of : public Function {
    Function& outer;
    Function& inner;

public:
    Of(const Function& outer, const Function& inner): outer(*outer.clone()), inner(*inner.clone()) {}

    double evaluate(double x) const override {
        return outer(inner(x));
    }

    std::string to_string(Function* func) const override{
        return outer.to_string(&inner);
    }

    // Chain rule: (f(g(x)))' = g'(x) * f'(g(x))
    Multiply& differentiate() const override{
        return inner.differentiate() * outer.differentiate()(inner);
    }

    Of(const Of& other): outer(*other.outer.clone()), inner(*other.inner.clone()){}

    Of* clone() const override{
        return new Of(*this);
    }

};

Of Function::operator()(const Function& inner) const{
    return {*this->clone(), *inner.clone()}; // Braces substitute a constructor; Braced initializer
}
#endif //FUNCTIONS_OF_H
