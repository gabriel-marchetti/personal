#include <bits/stdc++.h>

using namespace std;


void compute_LPS_array( string P, long long m, long long * lps ){
    long long len = 0;
    lps[0] = 0;

    long long i = 1;
    while( i < m ){
        if( P[i] == P[len] ){
            len++;
            lps[i] = len;
            i++;
        } else {
            if ( len != 0 ) len = lps[len-1];
            else{
                lps[i] = 0;
                i++;
            }
        }
    } 

}


void KMP_search( string P, string T ){
    long long m = P.size(), n = T.size();
    long long lps[m];

    compute_LPS_array(P, m, lps);

    long long i{0}, j{0};
    while( i < n ){
        if( P[j] == T[i] ){
            j++;
            i++;
        }

        if( j == m ){
            printf("Found the pattern at index %lld\n", i - j );
            j = lps[j-1];
        } else if ( i < n && P[j] != T[i] ){
            if ( j != 0 ) j = lps[j-1];
            else i++;
        }
    }
}


int main(void)
{
    string P = "AAAB";
    string T = "AAAAAAAAAAAAAAAAAAAAAAB";
    KMP_search(P, T);


    return 0;
}