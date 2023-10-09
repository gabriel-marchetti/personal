#include <iostream>

int main()
{
    char string[100]{};
    std::cin >> string;

    int i{0};
    int h1{-1}, e1{-1}, l1{-1}, l2{-1}, o1{-1}, flag{0};
    while( string[i] != '\0' ){
        if( h1 >= 0 && e1 >= 0 && l1 >= 0 && l2 >= 0 && o1 >= 0 ){ 
            break;
        }
        
        if ( string[i] == 'h' && h1 == -1){
            h1 = i;
        } else if ( string[i] == 'e' && h1 >= 0 && e1 == -1){
            e1 = i;
        } else if ( string[i] == 'l' && e1 >= 0 && l1 == -1){
            l1 = i;
        } else if ( string[i] == 'l' && l1 >= 0 && l2 == -1){
            l2 = i;
        } else if ( string[i] == 'o' && l2 >= 0 && o1 == -1){
            o1 = i;
        }
        i++; 
    }

    if( h1 >= 0 && e1 >= 0 && l1 >= 0 && l2 >= 0 && o1 >= 0 ){
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    return 0;
}