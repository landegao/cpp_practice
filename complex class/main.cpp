#include <iostream>
#include "Complex.h"

int main(){
    Complex c(3,-2);
    Complex d(2,5);
    Complex e(Complex(12,5));
    c =  d + 2 ;
    std::cout<< e << std::endl;
    return 0;
}
