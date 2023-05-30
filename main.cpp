
#include <iostream>
#include "functions/polynomial.h"

int main() {
    Polynomial p({1, 2, 3, 4});

    std::cout << p << std::endl;
    std::cout << p.differentiate();
}
