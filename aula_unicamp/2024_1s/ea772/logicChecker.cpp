#include <bits/stdc++.h>

#define MAX_BITS 64

/**
 * This function should add one to the binary representation of bits.
 * 
 * @param bits 
 */
void step( const bitset<MAX_BITS> bits ){
    // Find Least Significant Bit:
    int LSB{MAX_BITS};
    while( bits.test(LSB) ){
        LSB--;
    }

    
}

using namespace std;
int main(){
    int nBits;
    bitset<MAX_BITS> tests, stopCondition;
    stopCondition.set(); tests.reset();
    std::cin >> nBits;



}