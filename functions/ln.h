//
// Created by leonard04 on 5/30/23.
//

#ifndef FUNCTIONS_LN_H
#define FUNCTIONS_LN_H


#include "function.h"
#include "exponential.h"
#include <cmath>

class Ln : public Function{
public:
    double evaluate(double x) const override{
        return log(x);
    }
    std::string to_string(Function* func) const override{
        std::string x = func == nullptr ? "x" : func->to_string();
        return "ln(" + x + ")";
    }

    Function& differentiate() const override {
        return *new Power(-1); // dln(x)/dx -> 1/x
    }

    Function* clone() const override{
        return new Ln();
    }
};


#endif //FUNCTIONS_LN_H
