#include <bits/stdc++.h>

bool next_perm( int *array, int n, int begin);
void reverse( int *array, int begin, int end );
void swap( int *array, int i, int j );
void printArray( int *array, int n );

/**
 * This code is supposed to implement the std::next_permutation of an array.
 * For this task we will follow the Wikipedia's idea of generating the next
 * permutation of a lexigraphic ordering.
 * Link: https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order
 * Steps:
 *     Suppose that a is an array of size n+1.
 *     (1): Find the largest index k such that a[k] < a[k+1]. 
 *          If this doest not exist, then we are at the last permutation...
 *     (2): Find the largest index l such that a[k] < a[l]
 *     (3): Swap content of a[k] <-> a[l]
 *     (4): Reverse the order of a[k+1] -> a[n]
 */

bool next_perm( int *array, int n, int begin){
    /**
     * Output: It should reverse the array from a[begin, end] and return true
     *         if she can do it.
     */
    // Step 1:
    int k{n}; 
    k = k - 2; // 0-index array and we want the penultimate.
    while( array[k] >= array[k+1] ){
        if( k == begin ) return false;
        k--;
    }

    // Step 2:
    int l{n};
    l--; // 0-index array.
    while( array[k] >= array[l] ){
        if( l == begin ) return false;
        l--;
    }
    
    // Step 3:
    swap(array, k, l);

    // Step 4:
    reverse(array, k+1, n);
    return true;
}

void reverse( int *array, int begin, int end ){
    /**
     * The initial idea didn't include (*), but if that line doesn't exist we
     * get an error!
     * 
     * Try to get rid of that line and use an array of size even, you will see
     * that just doing end--, begin++ will skip the encounter index.
     */
    int tmp;
    end--;
    while( begin != end ){
        tmp = array[begin];
        array[begin] = array[end];
        array[end] = tmp;
        end--;
        if( begin == end ) break; // (*)
        begin++;
    }
}

void swap( int *array, int i, int j ){
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}

void printArray( int *array, int n ){
    for(int i{0}; i < n; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}


int main(){

    /**
     *  Testing function next_perm. 
     */
    int array[] = {0, 1, 2, 3};
    while( next_perm(array, 4, 0) )
        printArray( array, 4 );

    return 0;
}