#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a{}, b{}, c{}, d{};
    cin >> a >> b >> c >> d;
    double p1{}, p2{}, prob{}, iter{};

    p1 = (double) a/b;
    p2 =  1 - (double) c/d;

    iter = 3*ceil((log10(1/p1*10e-6)/(log10((1-p1)*(1-p2)))));
    for(int i{0}; i < iter; i++){
        prob += p1*pow((1-p1), i)*pow((1-p2), i);
    }

    cout << setprecision(12);
    cout << prob;
}