//
// Created by leonard04 on 10/27/23.
//

#ifndef FUNCTIONS_TRIG_H
#define FUNCTIONS_TRIG_H

#include "function.h"
#include <cmath>

class Sin;
class Cos;


class Sin: public Function{

public:
    double evaluate(double x) const override {
        return sin(x);
    }

    std::string to_string(Function* func) const override {
        std::string x = func == nullptr ? "x" : func->to_string();
        return "sin(" + x + ")";
    }

    Function& differentiate() const override;

    Function* clone() const override{
        return new Sin();
    }
};

class Cos: public Function{
    double evaluate(double x) const override {
        return cos(x);
    }

    std::string to_string(Function* func) const override {
        std::string x = func == nullptr ? "x" : func->to_string();
        return "cos(" + x + ")";
    }

    Function& differentiate() const override {
        return *new Sin();
    }

    Function* clone() const override{
        return new Cos();
    }
};

// Defined outside to use cos
Function& Sin::differentiate() const {
    return *new Cos();
}
#endif //FUNCTIONS_TRIG_H
