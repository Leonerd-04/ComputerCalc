//
// Created by leonard04 on 5/30/23.
//

#ifndef FUNCTIONS_OF_H
#define FUNCTIONS_OF_H


#include "function.h"

class Of : public Function {
    Function* outer;
    Function* inner;

public:
    Of(Function* outer, Function* inner) {
        this->outer = outer;
        this->inner = inner;
    }

};

Of Function::operator()(const Function& inner) const{
    return Of(this->clone(), inner.clone());
}
#endif //FUNCTIONS_OF_H
