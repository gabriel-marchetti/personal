#include<bits/stdc++.h>
#define MAX 3010
using namespace std;

int main(){
    bitset<MAX> alreadyVisited;
    int array[MAX];

    int n, diff;
    while( cin >> n ){
        alreadyVisited.reset();
        for(int i{0}; i < n; i++)
            cin >> array[i];

        for(int i{0}; i < n - 1; i++){
            diff = abs( array[i] - array[i+1] );
            if( diff <= (n-1) )
                alreadyVisited.set(diff);
        }

        bool flag{true};
        for( int i{1}; i < n; i++){
            if( alreadyVisited[i] == 0 ){
                cout << "Not jolly" << endl;
                flag = false;
                break;
            }
        }

        if(flag)
            cout << "Jolly" << endl;
    }


    return 0;
}