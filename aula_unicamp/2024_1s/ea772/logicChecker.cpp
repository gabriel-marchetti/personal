#include <bits/stdc++.h>

#define MAX_BITS 64
using namespace std;

/**
 * This function should add one to the binary representation of bits.
 * 
 * @param bits 
 */
void step( vector<int> &vec ){
    for( vector<int>::iterator it = vec.end() - 1; it != vec.begin() - 1; it-- ){
        if( *it ){
            *it = 0;
        }
        else{
            *it = 1;
            break;
        }
    }
}

void printVec( vector<int> &vec ){
    for( vector<int>::iterator it = vec.begin(); it != vec.end(); it++ )
        cout << *it << ' ';
    cout << ' ';
}

int _not( int A ){
    if( A )
        return 0;
    return 1;
}

int __expression( int nBits, vector<int> &vec ){
    int result;
    // cout << endl;
    // cout << "Vec[0] = " << vec[0] << endl;
    // cout << "Vec[1] = " << vec[1] << endl;
    // cout << endl; 

    // A0 - LSB
    // A1
    // A2
    // A3 - MSB
    int A3 = vec[0], A2 = vec[1], A1 = vec[2], A0 = vec[3];
    
    // ( A3 + A2 * (A1 + A0) )
    result = ( A3 + A2 * (A1 + A0) ) * _not(A3*A2); 

    if( result )
        return 1;
    return 0;
}

int main(){
    vector<int> tests, stopCondition;
    int nBits;
    cout << "Number of Bits: ";
    cin >> nBits;
    tests.resize( nBits ); stopCondition.resize( nBits );
    tests.assign( nBits, 0 ); stopCondition.assign( nBits, 0 );

    char letters = 'A';
    for(int i{0}; i < nBits; i++){
        printf("%c ", letters + i);
    }
    printf("\t RESULT:");
    cout << endl;

    int partialResult;
    do{
        printVec(tests);
        partialResult = __expression( nBits, tests );
        printf("\t %d\n", partialResult);  
        step(tests);
    }while( stopCondition != tests );

    return 0;
}