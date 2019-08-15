#include <iostream>
#include "nullable.h"

int main(int argc, char* argv[]) {
    Nullable<int> integerA ;

    if (!integerA) {
        std::cout << "Integer is not set" << std::endl ;
    }

    if (int a = integerA = 45) {
        std::cout << "Integer was setted with value " << a << std::endl ;
    }

    Nullable<int> integerB ;

    // std::cout << int(integerB) << std::endl ; throws the error
    integerB = 30 ;

    if (!(integerA == integerB)) {
        std::cout << "Are not equals" << std::endl ;
        std::cout << "Assign integerA value to integerB value" << std::endl ;
        integerB = integerA ;
    }

    std::cout << "Are equals now? " << (integerA == integerB) << std::endl ;

    return 0 ;
}
