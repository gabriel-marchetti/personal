#include <bits/stdc++.h>

int main(){
    int N;

    while( std::cin >> N ){
        if( N == 0 ) break;

        for( int fghij{1234}; fghij <= 98765 / N; fghij++ ){
            int abcde = fghij * N;
            int tmp, used = ( fghij < 10000 );
            tmp = abcde;
            while( tmp ){
                used |= 1 << (tmp % 10);
                tmp /= 10;
            }
            tmp = fghij;
            while( tmp ){
                used |= 1 << (tmp % 10);
                tmp /= 10;
            }

            if( used == ( 1 << 10 ) - 1 ){
                printf("%05d / %05d = %d\n", abcde, fghij, N);
            }
        }
    }

    return 0;
}