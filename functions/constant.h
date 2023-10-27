//
// Created by leonard04 on 5/30/23.
//

#ifndef FUNCTIONS_CONSTANT_H
#define FUNCTIONS_CONSTANT_H

#include "function.h"
#include "combinations/multiply.h"

// Useful to not need to make special cases with other classes
class Constant : public Function {
    const double c;
public:
    Constant(double c) : c(c){}

    double evaluate(double x) const override {
        return c;
    }

    std::string to_string(Function* func) const override {
        return std::to_string(c);
    }


    Constant& differentiate() const override {
        return *new Constant(0);
    }


    Constant(const Constant& other) : c(other.c){}

    Function* clone() const override{
        return new Constant(*this);
    }
};

// Makes multiplying by constants easier
Multiply& operator*(const double c, const Function& f){
    return *new Multiply(Constant(c), f);
}

#endif //FUNCTIONS_CONSTANT_H
