//
// Created by leonard04 on 5/30/23.
//

#ifndef FUNCTIONS_EXPONENTIAL_H
#define FUNCTIONS_EXPONENTIAL_H


#include "function.h"
#include "constant.h"
#include "combinations/multiply.h"
#include <cmath>
#include <typeinfo>

class Exponential : public Function{
    double base;
public:
    Exponential(double base = M_E) : base(base) {}

    double evaluate(double x) const override {
        return pow(base, x);
    }

    std::string to_string(Function *func) const override{
        std::string x = func == nullptr ? "x" : ("(" + func->to_string() + ")");
        return std::to_string(base) + "^" + x;
    }

    Function& differentiate() const override{
        return log(base) * *this;
    }


    Exponential* clone() const override{
        return new Exponential(base);
    }
};

class Power : public Function{
    double power;
public:
    Power(double power) : power(power){}

    double evaluate(double x) const override{
        return pow(x, power);
    }

    std::string to_string(Function* func) const override{
        std::string x = func == nullptr ? "x" :  "(" + func->to_string() + ")";
        return x + "^" + std::to_string(power);
    }
    Multiply& differentiate() const override{
        return power * Power(power - 1);
    }

    Power(const Power& other) : power(other.power){}

    Power* clone() const override{
        return new Power(*this);
    }
};

#endif //FUNCTIONS_EXPONENTIAL_H
