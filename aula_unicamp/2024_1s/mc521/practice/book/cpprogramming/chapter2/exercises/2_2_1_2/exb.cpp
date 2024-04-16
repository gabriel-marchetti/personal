#include <bits/stdc++.h>
#define MAX 101
using namespace std;

int main(){
    int S[MAX];
    int size;
    cout << "Size Array: ";
    cin >> size;
    if( size >= MAX ) cout << "Max sized array is 100\n";


    /**
     * Generating a pseud-random array for testing the algorithm... 
     */
    for(int i{0}; i < size; ++i){
        S[i] = rand() % 100;
    }
    sort( S, S + size );
    for( int i{0}; i < size; ++i){
        printf("%d ", S[i]);
    } printf("\n");


    /**
     * Use a two-pointer approach to find target at time-complexity of O(n)
     * Algorithm step-by-step:
     * 1) initialize back_ptr to start of the array and back_ptr to the end of
     *    the array.
     * 2) 
     *      2.1) if target found, then you have located the pair
     *      2.2) if sum of S[back_ptr] + S[front_ptr] < target then we need to 
     *           increase the value.
     *      2.3) else we need to decrease!
     * 3) if not found, then there is no pairs.
     *  
     */
    int back_ptr = 0, front_ptr = size - 1;
    int target;
    cout << "Target: ";
    cin >> target;

    /**
     * To find all pairs we could just get rid of the break and count if a solution
     * was found. 
     */
    while( back_ptr != front_ptr ){
        int sum = S[back_ptr] + S[front_ptr];
        if( sum == target ) break;
        else if( sum < target ) back_ptr++;
        else front_ptr--;
    }
    if( back_ptr == front_ptr ) cout << "No pair found\n";
    else printf("%d + %d = %d\n", S[back_ptr], S[front_ptr], target);

    return 0;
}