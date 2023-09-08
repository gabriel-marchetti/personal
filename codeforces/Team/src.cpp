#include <iostream>

int main()
{
    int n{ };
    std::cin >> n;

    int decision[3]{};
    int problems{0}, pdecision{0};

    for(int i{0}; i < n; i++){
        pdecision = 0;
        for(int j{0}; j < 3; j++){
            std::cin >> decision[j];
            if ( decision[j] == 1){
                pdecision++;
            }
        }

        if ( pdecision >= 2){
            problems++;
        }
    }

    std::cout << problems << '\n';

    return 0;
}