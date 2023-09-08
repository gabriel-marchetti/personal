#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long N{0}, F{0}, totalbill{0}, scan{0};
    int bill{1};

    do
    {
        totalbill = 0;
        cin >> N >> F;
        for(int i{0}; i < N; i++){
            cin >> scan;
            totalbill += scan;
        }

        if ( N != 0 || F != 0 ){
            cout << "Bill #" << bill << " costs " << totalbill << ": each friend sould pay " << totalbill/F << '\n'; 
        }
        bill++;

    } while ( F != 0 && N != 0);
    

    return 0;
}