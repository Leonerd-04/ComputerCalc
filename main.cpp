
#include <iostream>
#include "functions/polynomial.h"

int main() {
    Polynomial p({1, 2, 3, 4});
    Polynomial q({0, 0, 2});

    std::cout << q.to_string(&p) << std::endl;
    std::cout << p.differentiate();
    std::cout << p.differentiate();
}
