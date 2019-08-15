#include <iostream>
#include "nullable.h"

class SomeClass {
public:
    void doSomething(void) {
        std::cout << "Doing something..." << std::endl ;
    }
} ;


int main(int argc, char* argv[]) {
    Nullable<int> integerA ;

    if (!integerA) {
        std::cout << "IntegerA is not set" << std::endl ;
    }

    if (int a = integerA = new int(45)) {
        std::cout << "IntegerA was setted with value " << a << std::endl ;
    }

    if (45 == integerA) {
        std::cout << "IntergerA is equal to " << 45 << std::endl ;
    }

    Nullable<int> integerB ;

    // std::cout << int(integerB) << std::endl ; throws an error
    integerB = new int(30) ;

    if (!(integerA == integerB)) {
        std::cout << "Are not equals" << std::endl ;
        std::cout << "Assign integerA value to integerB value" << std::endl ;
        integerB = integerA ;
    }

    std::cout << "Are equals now? " << (integerA == integerB) << std::endl ;

    Nullable<SomeClass> someObject ;
    // SomeClass(someObject).doSomething() ; throws an error
    someObject = new SomeClass() ;
    someObject -> doSomething() ;

    return 0 ;
}
