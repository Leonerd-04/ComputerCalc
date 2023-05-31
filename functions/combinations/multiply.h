//
// Created by leonard04 on 5/30/23.
//

#ifndef FUNCTIONS_MULTIPLY_H
#define FUNCTIONS_MULTIPLY_H


#include "../function.h"
#include "addition.h"

// Multiplies two functions
class Multiply : public Function{
    Function* f;
    Function* g;

public:
    Multiply(Function* f, Function* g) :f(f->clone()), g(g->clone()){}

    double evaluate(double x) const override{
        return (*f)(x) * (*g)(x);
    }

    std::string to_string(Function* func) const override {
        return "(" + f->to_string() + ")(" + g->to_string() +  ")";
    }

    // Product rule: (fg)' = f'g + fg'
    Addition& differentiate() const override{
        Addition a = Multiply(&f->differentiate(), g) + Multiply(f, &g->differentiate());
        return a;
    }

    Multiply(const Multiply& other){
        this->f = other.f->clone();
        this->g = other.g->clone();

    }

    Multiply* clone() const override {
        return new Multiply(*this);
    }

};


#endif //FUNCTIONS_MULTIPLY_H
