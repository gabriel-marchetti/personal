#include <bits/stdc++.h>

int main(void)
{
    int digit;
    std::cout << "Digite 0, 1, 2" << std::endl;
    std::cin >> digit;
    if( digit == 1 ){
        std::cout << "André é o melhor jogador do mundo!" << std::endl;
        std::cout << "Para ver a resposta de qual jogo digite QUERO!" << std::endl;
        std::string s;
        std::cin >> s;
        if ( s[0] == 'Q' || s[0] == 'q' ){
            std::cout << "Vai ser de fute mesmo UHULLL!!!" << std::endl;
        }
    }
    else if ( digit == 2 )
        std::cout << "O verdão é o melhor do mundo" << std::endl;

    return 0;
}