//
// Created by leonard04 on 5/30/23.
//

#ifndef FUNCTIONS_FUNCTION_H
#define FUNCTIONS_FUNCTION_H


#include <string>

class Of;

// Base function class, totally virtual
class Function {
public:
    virtual constexpr double evaluate(double x) const = 0;
    virtual std::string to_string(Function* func) const = 0;
    virtual Function& differentiate() const = 0;

    virtual Function* clone() const = 0;

    // Essentially gives to_string a default value
    std::string to_string() const {
        return to_string(nullptr);
    }

    // Allows for simple plugging in
    // A function f can be evaluated at 2 via f(2) for example
    double operator()(double x) const {
        return evaluate(x);
    }

    // Allows composition; i.e. cos(x²), via calling f(g) directly for two functions f and g
    Of operator()(const Function& inner) const;
};

std::ostream& operator<<(std::ostream& os, const Function& function){
    os << function.to_string();
    return os;
}


#endif //FUNCTIONS_FUNCTION_H
