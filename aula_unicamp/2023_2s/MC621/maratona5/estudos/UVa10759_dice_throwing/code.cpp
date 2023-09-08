#include <bits/stdc++.h>

using namespace std;

void DT(uint64_t k, uint64_t soma, uint64_t x, uint64_t *cases)
{
    if ( k == 0 && soma < x){
        return;
    } else if ( k == 0 && soma >= x ){
        *cases++;
    } else {
        for(int i{0}; i < 6; i++){
            DT(k-1, soma-i, x, cases);
        }
    }
}

int main(void)
{
    uint64_t n{0}, x{0}, cases{0}, total{0};

    do{
        cin >> n >> x;
        total = pow(6, n);
        DT(n, 0, x, &cases);

        cout << cases << "/" << total << endl;
        
    } while ( n != 0 || x != 0 );

    return 0;
}