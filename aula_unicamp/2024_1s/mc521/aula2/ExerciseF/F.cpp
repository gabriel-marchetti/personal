#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, numDigits{0};
    cin >> n;

    long long times{1};
    while( n > pow(10, times) ){
        numDigits += 9*pow(10, times - 1)*times;
        times++;
    }

    numDigits += ( n + 1 - pow(10, times - 1) ) * times;
    cout << numDigits << endl;

    return 0;
}