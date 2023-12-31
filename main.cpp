
#include <iostream>
#include "functions/polynomial.h"
#include "functions/exponential.h"
#include "functions/combinations/of.h"
#include "functions/trig.h"

int main() {
    Polynomial p({10, 3, 4});
    Polynomial q({0, 0, 2});


    std::cout << "The derivative of " << q(p) << " is " << q(p).differentiate() << std::endl;

    Exponential ex; // Default exponential is e^x

    std::cout << ex << std::endl;
    std::cout << "e^2 is " << ex(2) << std::endl;
    std::cout << "The derivative of " << ex << " is " << ex.differentiate() << std::endl;

    Of ex3 = ex(Power(3));

    std::cout << ex3 << std::endl;
    std::cout << "e^8 is " << ex3(2) << std::endl;
    std::cout << "The derivative of " << ex3 << " is " << ex3.differentiate() << std::endl;
    std::cout << "The slope of the graph at x = 1 is " << ex3.differentiate()(1) << std::endl;

    Of c = Cos()(Power(2)); // cos(x²)

    std::cout << c << std::endl;
    std::cout << "cos(4) is " << c(2) << std::endl;
    std::cout << "The derivative of " << c << " is " << c.differentiate() << std::endl;
    std::cout << "The slope of the graph at x = pi is " << ex3.differentiate()(M_1_PIf) << std::endl;

}
