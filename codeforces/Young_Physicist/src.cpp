#include <iostream>

int main()
{
    int n{};
    std::cin >> n;

    int x{}, y{}, z{};
    long int sumX{0}, sumY{0}, sumZ{0};

    for(int i{0}; i < n; i++){
        std::cin >> x >> y >> z;
        sumX = sumX + x;
        sumY = sumY + y;
        sumZ = sumZ + z;
    }

    if ( sumX == 0 && sumY == 0 && sumZ == 0){
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    
    return 0;
}