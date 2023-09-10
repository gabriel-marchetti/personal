#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int num{0}, n{0}, remainder{0}, flag{1};
    cin >> num;
    int lucknumber[] = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777};

    n = num;
    while( n ){
        remainder = n % 10;
        n         = n / 10;

        if( remainder != 4 || remainder != 7 ){
            flag = 0;
            break;
        }
    }

    // Difficult cases:
    if(flag == 0){
        for(int i{0}; i < 14; i++){
            if( num % lucknumber[i] == 0 ){
                flag = 1;
            }
        }
    }

    if(flag) printf("YES\n");
    else printf("NO\n");

    return 0;
}