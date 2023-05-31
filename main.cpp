
#include <iostream>
#include "functions/polynomial.h"
#include "functions/exponential.h"
#include "functions/combinations/of.h"

int main() {
    Polynomial p({1, 2, 3, 4});
    Polynomial q({0, 0, 2});

    std::cout << q.to_string(&p) << std::endl;
    std::cout << p.differentiate();

    Exponential ex; // Default exponential is e^x

    std::cout << ex << std::endl;
    std::cout << "e^2 is " << ex(2) << std::endl;
    std::cout << "The derivative of " << ex << " is " << ex.differentiate() << std::endl;

    Of ex3 = ex(Power(3));

    std::cout << ex3 << std::endl;
    std::cout << "e^8 is " << ex3(2) << std::endl;
    std::cout << "The derivative of " << ex3 << " is " << ex3.differentiate() << std::endl;
    std::cout << "The slope of the graph at x = 1 is " << ex3.differentiate()(1) << std::endl;
}
