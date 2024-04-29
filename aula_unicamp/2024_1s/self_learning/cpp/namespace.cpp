#include <iostream>

namespace space1{
    void imprime(){
        std::cout << "Imprimindo no primeiro namespace" << std::endl;
    }
}

namespace space2{
    void imprime(){
        std::cout << "Imprimindo no segundo namespace" << std::endl;
    }
}

int main(){
    space1::imprime();
    space2::imprime();

    return 0;
}