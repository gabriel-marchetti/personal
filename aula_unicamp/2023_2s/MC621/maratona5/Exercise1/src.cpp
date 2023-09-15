#include <bits/stdc++.h>

int main(void)
{
    int t; scanf("%d", &t);

    int n;
    while(t--){
        scanf("%d", &n);
        printf( n < 5 ? "Bob\n" : "Alice\n" );
    }

    return 0;
}