#include <bits/stdc++.h>

using namespace std;

long double compute(long int S, long double p, long int I){
    long double total{0}, partial{0};
    int i{1}; 
    partial = pow(1-p, I-1)*p;
    while ( partial >= 10e-7){
        total += partial;
        partial = pow(1-p, i*S)*pow(1-p, I-1)*p;
        i++;
    }

    return total;
}

int main(void)
{
    int t{0};
    cin >> t;
    long int S{0}, I{0};
    long double p{0}, r{0};

    for(int i{0}; i < t; i++){
        cin >> S >> p >> I;
        r = compute(S, p, I);
        printf("%.4Lf\n", r);
    }

    return 0;
}