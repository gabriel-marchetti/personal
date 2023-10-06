#include <bits/stdc++.h>
#include <math.h>

using namespace std;
int main(void)
{
    string N;
    double F, F0;
    while( cin >> N ){
        F0 = sqrt(2) + sqrt(3) + sqrt(6);
        F  = F0;
        int digito = N[ N.size() - 1 ] - '0';
        if ( N.size() == 1 && N[0] < '3' ){
            for( int n = 0; n < stoi(N); n++ )
                F = (F*F - 5)/(2*F+4);
            cout << fixed << showpoint;
            cout << setprecision(10);
            cout << F << endl;
        }
        else {
            if ( digito % 2 == 0 ) cout << "-2.5773502692" << endl;
            else cout << "-1.4226497308" << endl;
        }
    }

    return 0;
}
