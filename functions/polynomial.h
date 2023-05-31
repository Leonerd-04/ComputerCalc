//
// Created by leonard04 on 5/30/23.
//

#ifndef FUNCTIONS_POLYNOMIAL_H
#define FUNCTIONS_POLYNOMIAL_H


#include <vector>
#include "function.h"
#include <sstream>

class Polynomial : public Function {
    std::vector<double> coefficients;

    public:

    Polynomial(const std::vector<double> coefficients): coefficients(coefficients) {}

    Polynomial(std::initializer_list<double> list) : coefficients(list){}

    double evaluate(double x) const override{
        double y = 0;
        double x_n = 1; //x to the power of n

        for(double c : coefficients){
            y += c * x_n;
            x_n *= x;
        }
        return y;
    }

    Function& differentiate() const override{
        std::vector<double> newCoef;

        for(int i = 1; i < coefficients.size(); i++){
            newCoef.push_back(coefficients[i] * i);
        }

        static Polynomial p(newCoef);
        return p;
    }

    std::string to_string(Function* func) const override{
        std::string x = "x";

        if(func != nullptr){
            x = "(" + func->to_string() + ")";
        }

        std::stringstream result;
        double c;
        for(int i = 0; i < coefficients.size(); i++){
            c = coefficients[i];

            if(c == 0) continue;

            result << (c > 0 ? " + " : " - ");

            // Don't display 1x^n, just x^n. Do display 1
            if((c != 1 && c != -1) || i == 0) {
                result << abs(c); // abs(c) is used because we already accounted for negatives above
            }

            if(i == 0) continue; // Don't display cx^0, just c

            result << x;

            // Don't display x^1, just x
            if(i != 1){
                result << "^" << i;
            }
        }

        return result.str();
    }

};


#endif //FUNCTIONS_POLYNOMIAL_H
