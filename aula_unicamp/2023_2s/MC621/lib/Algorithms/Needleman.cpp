#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    char P[20] = "ACAATCC", Q[20] = "AGCATGC";
    int n = (int)strlen(P), m = (int)strlen(Q);
    int i, j, table[20][20];
    memset(table, 0, sizeof table);
    for( i = 1; i <= n; i++ ) table[i][0] = i * -1;
    for( j = 1; j <= m; j++ ) table[0][j] = j * -1;

    for( i = 1; i <= n; i++ ){
        for( j = 1; j <= m; j++ ){
            // P[i - 1] because P is a string which starts at index 0.
            // Note that in the table 0 is empty sub-strings so it does not correspond
            // to the zeroth position of the string.
            table[i][j] = table[i-1][j-1] + ( P[i - 1] == Q[j - 1]  ? 2 : 1 );
            table[i][j] = max(table[i][j], table[i - 1][j] - 1);
            table[i][j] = max(table[i][j], table[i][j - 1] - 1);
        }
    }
    printf("DP table :\n");
    for(i = 0; i <= n; i++){
        for(j = 0; j <= m; j++)
            printf("%3d", table[i][j]);
        printf("\n");
    }
    printf("Maximum Alignment Score: %d\n", table[n][m]);

    return 0;
}