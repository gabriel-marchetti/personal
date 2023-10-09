#include <iostream>

int main()
{
    char string[100]{};
    std::cin >> string;

    int numH{0}, numO{0}, numL{0}, numE{0};
    int i{0};
    while( string[i] != '\0' ){
        if( string[i] == 'h' && numH <= 0){
            numH++;
        } else if ( string[i] == 'o' && numO <= 0){
            numO++;
        } else if ( string[i] == 'l' && numL <= 1){
            numL++;
        } else if ( string[i] == 'e' && numE <= 0){
            numE++;
        }
        i++;
        if ( numH >= 1 && numO >= 1 && numL >= 2 && numE >= 1){
            std::cout << "YES" << std::endl;
            return 0;
        }
    }

    std::cout << "NO" << std::endl;

    return 0;
}