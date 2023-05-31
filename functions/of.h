//
// Created by leonard04 on 5/30/23.
//

#ifndef FUNCTIONS_OF_H
#define FUNCTIONS_OF_H


#include "function.h"

// Takes one function's output of another
// Like outer(inner(x))
class Of : public Function {
    Function* outer;
    Function* inner;

public:
    Of(Function* outer, Function* inner) {
        this->outer = outer;
        this->inner = inner;
    }

    double evaluate(double x) const override {
        return outer->evaluate(inner->evaluate(x));
    }

    std::string to_string(Function* func) const override{
        return outer->to_string(inner);
    }

    Function& differentiate() const {
        return outer->differentiate(); // We cannot properly differentiate until we can multiply functions
    }

    Of(const Of& other){
        this->outer = other.outer;
        this->inner = other.inner;
    }

    Of* clone() const override{
        return new Of(*this);
    }

};

Of Function::operator()(const Function& inner) const{
    return Of(this->clone(), inner.clone());
}
#endif //FUNCTIONS_OF_H
