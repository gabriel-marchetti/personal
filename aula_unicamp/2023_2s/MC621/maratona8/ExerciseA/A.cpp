#include <bits/stdc++.h>

using namespace std;

struct dados{
    int appeared;
    long long first;
};

int main(void)
{
    int Q;
    cin >> Q;
    long long k;
    long long fib_0, fib_1, aux;
    long long mod, index;

    for(int i{0}; i < Q; i++){
        cin >> k;
        dados array[k] = { 0 };
        fib_0      = 1;
        fib_1      = 1;
        index      = 2;
        while(true){
            aux   = fib_1 % k;
            fib_1 = (fib_1 % k + fib_0 % k) %k;
            fib_0 = aux;
            mod   = fib_1;
            if( array[mod].appeared != 0 ) break;
            
            array[mod].first    = index;
            array[mod].appeared += 1;  
            index++; 
        }

        cout << array[mod].first << endl;
    }

    return 0;
}