#include <bits/stdc++.h>
#define MAXN 100010

using namespace std;
long long OWLS[MAXN], N, M, Q;

long long max_force( long long v ){
    while( OWLS[v] >= 0 )
        v = OWLS[v];
    return OWLS[v];
}

void insert_relation( long long read1, long long read2 ){
    long long parent, force;
}

int main( ){
    cin >> N >> M;
    for(int i{1}; i <= N; i++)
        OWLS[i] = -i;
    long long force, parent, read1, read2;
    for(int i{1}; i <= M; i++){
        cin >> read1 >> read2;
        insert_relation(read1, read2);
    }

    for(int i{1}; i <= N; i++)
        cout << OWLS[i] << ' ';
    cout << endl;

    cin >> Q;
    long long number1, number2;
    for(int i{0}; i < Q; i++){
        cin >> read1 >> read2;
        number1 = max_force(read1);
        number2 = max_force(read2);
        if( number1 == number2 )
            cout << "TIE" << endl;
        else if( number1 > number2 )
            cout << read1 << endl;
        else
            cout << read2 << endl;
    }

    return 0;
}