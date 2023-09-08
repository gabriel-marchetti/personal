#include <bits/stdc++.h>

using namespace std;

int factorial(int hats)
{
    if (hats == 0) return 1;
    else return hats*factorial(hats-1);
}

int derange(int hats)
{
    if (hats == 0){
        return 1;
    } else if ( hats == 1 ){
        return 0;
    } else {
        return (hats - 1)*( derange(hats-1) + derange(hats-2) );
    }
}

int main(void)
{
    int t{0}, hats{0}, suce{0}, total{0};
    cin >> t;
    for(int i{0}; i < t; i++){
        cin >> hats;
        suce    = derange(hats);
        total   = factorial(hats);

        printf("%d/%d\n", suce, total);
    }

    return 0;
}