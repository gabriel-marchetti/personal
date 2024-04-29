#include <iostream>

int main(){
    float x;
    std::cin >> x;
    if( std::cin.fail() ){
        std::cout << "Erro na leitura dos dados." << '\n';
        std::cin.clear();
    }
    else{
        std::cout.setf(std::ios::fixed);
        std::cout.precision(2);
        std::cout << x << '\n';
    }

    return 0;
}