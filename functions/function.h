//
// Created by leonard04 on 5/30/23.
//

#ifndef FUNCTIONS_FUNCTION_H
#define FUNCTIONS_FUNCTION_H


#include <string>

class Function {
    Function& input;
    virtual double evaluate() const = 0;
    virtual Function& differentiate() const = 0;
    virtual std::string display() const = 0;

public:
    Function() = default;

};


#endif //FUNCTIONS_FUNCTION_H
