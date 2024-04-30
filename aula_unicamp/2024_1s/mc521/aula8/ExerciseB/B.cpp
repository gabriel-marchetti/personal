#include <bits/stdc++.h>
#define MAX_N 200010
using namespace std;

int A[MAX_N];

long long num_subarrays_target( int n, long long target ){
    long long num_subarrays = 0, partial_sum = A[0];
    int start = 0, end = 0;
    
    /* start and end must achieve final index of array */
    while( start != n - 1 ){
        // printf("Start: %d\n", start);
        // printf("End: %d\n", end);
        // printf("--------\n");
        if( partial_sum == target ){
            num_subarrays++;
            if( end < n - 1 ){
                end++;
                partial_sum += A[end];                
            } 
            else{
                partial_sum -= A[start];
                start++;
            }
        }
        else if( partial_sum < target ){
            if( end < n - 1){
                end++;
                partial_sum += A[end];
            }
            else{
                partial_sum -= A[start];
                start++;
            }
        }
        else{
            if( start == end){
                end++;
                partial_sum += A[end];
            } 
            else{
                partial_sum -= A[start];
                start++;
            } 
        }
    }
    if( A[n-1] == target ) num_subarrays++;

    return num_subarrays;
}

int main(){
    int n;
    long long target;
    cin >> n >> target;
    for( int i = 0; i < n; ++i ){
        long long tmp;
        cin >> tmp;
        A[i] = tmp;
    }

    cout << num_subarrays_target( n, target ) << endl;

    return 0;
}