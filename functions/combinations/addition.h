//
// Created by leonard04 on 5/30/23.
//

#ifndef FUNCTIONS_ADDITION_H
#define FUNCTIONS_ADDITION_H

#include "../function.h"
class Addition;

Addition& operator+(const Function& f, const Function& g);

// Adds two functions together
class Addition : public Function{
    Function& f;
    Function& g;

public:

    Addition(const Function& f, const Function& g): f(*f.clone()), g(*g.clone()){}

    double evaluate(double x) const override {
        return f(x) + g(x);
    }

    std::string to_string(Function* func) const override {
        return f.to_string(func) + " + " + g.to_string(func);
    }

    Addition& differentiate() const override {
        return f.differentiate() + g.differentiate();
    }


    Addition(const Addition& other): f(*other.f.clone()), g(*other.g.clone()){
    }

    Function* clone() const override{
        return new Addition(*this);
    }
};


Addition& operator+(const Function& f, const Function& g){
    return *new Addition(f, g);
}


#endif //FUNCTIONS_ADDITION_H
