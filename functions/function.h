//
// Created by leonard04 on 5/30/23.
//

#ifndef FUNCTIONS_FUNCTION_H
#define FUNCTIONS_FUNCTION_H


#include <string>

class Function {
public:
    virtual double evaluate(double x) const = 0;
    virtual std::string to_string() const = 0;
    virtual Function& differentiate() const = 0;

    Function() = default;

    double operator()(double x) const {
        return evaluate(x);
    }
};

std::ostream& operator<<(std::ostream& os, const Function& function){
    os << function.to_string();
    return os;
}


#endif //FUNCTIONS_FUNCTION_H
