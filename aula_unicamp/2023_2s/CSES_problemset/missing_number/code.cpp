#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int array[n]{0};

    int reader;
    n--;
    while( n-- ){
        cin >> reader;
        array[reader-1] = 1;
    }

    reader = 0;
    while( array[reader] != 0) reader++;

    cout << reader + 1 << endl;

    return 0;
}