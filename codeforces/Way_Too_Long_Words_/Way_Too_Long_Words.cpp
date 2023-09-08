#include <iostream>

int main()
{
    int n{ };
    std::cin >> n;

    int size{ };
    char string[100]{ };
    for (int i{0}; i < n; i++){
        std::cin >> string;
        size = 0;
        while( string[size] != '\0'){
            size++;
        }
        
        if ( size <= 10 ){
            std::cout << string << '\n';
        } else {
            std::cout << string[0] << size - 2 << string[size-1] << '\n';
        }
    }

    return 0;
}