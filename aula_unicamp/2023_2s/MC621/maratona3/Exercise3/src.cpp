#include<bits/stdc++.h>

using namespace std;
typedef long l;

int main()
{
    l value{};
    cin >> value;
    int min{};

    while(value >= 1){
        if(value % 2){
            min++;
        }
        value = value / 2;
    }
    
    cout << min;
}