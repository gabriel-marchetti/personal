#include <bits/stdc++.h>

using namespace std;

unsigned compute( unsigned days )
{
    unsigned people{0};
    long double   prob{1}, aux{1}, ddays{0};

    do
    {
        ddays = (long double) days;
        aux *= (ddays - people) / ( ddays);
        prob = 1 - aux;
        people++;
    } while ( prob < 0.5 );
    
    return people - 1;
}

int main(void)
{
    unsigned T{0}, days{0}, people{0};
    cin >> T;
    for(int i{1}; i <= T; i++){
        people = 0;
        cin >> days;
        people = compute(days);
        cout << "Case " << i << ": " <<  people << endl;
    }

    return 0;
}