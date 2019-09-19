//
// Created by lhmily on 2019/9/12.
//

#include "impl.h"
#include <iostream>

int main(int argc, char **argv) {
    Base *base = new Impl();
    base->foo();
    std::cout << "test virtual function." << std::endl;
}