//
// Created by leonard04 on 5/30/23.
//

#ifndef FUNCTIONS_FUNCTION_H
#define FUNCTIONS_FUNCTION_H


#include <string>

class Of;

class Function {
public:
    virtual double evaluate(double x) const = 0;
    virtual std::string to_string(Function* func) const = 0;
    virtual Function& differentiate() const = 0;

    // virtual Function* create() const = 0;
    // virtual Function* clone() const = 0;

    // Essentially gives to_string a default value
    std::string to_string() const {
        return to_string(nullptr);
    }

    double operator()(double x) const {
        return evaluate(x);
    }

    Of operator()(const Function& inner) const;
};

std::ostream& operator<<(std::ostream& os, const Function& function){
    os << function.to_string();
    return os;
}


#endif //FUNCTIONS_FUNCTION_H
