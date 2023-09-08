#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int t{}; 
    ll l{}, r{}, unNum{}, number{};
    cin >> t;

    int top{}, bottom{10}, actual{}, aux{}, stand{10};
    for(int k{0}; k < t; k++){
        cin >> l >> r;
        stand = 10;
        for(ll i{l}; i <= r; i++){
            bottom  = 10;
            top     = 0;
            number  = i;
            while(number > 1){
                actual = number % 10;
                number = number / 10;
                if(actual > top){
                    top = actual;
                }
                if(actual < bottom){
                    bottom = actual;
                }
            }

            aux = top - bottom;
            if( aux < stand ){
                stand = aux;
                unNum = i;
            }
        } 

        cout << unNum << '\n';
    }

    return 0;
}