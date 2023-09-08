#include <stdio.h>

int main()
{
    int N, K;
    scanf("%d %d\n", &N, &K);

    int array[N];
    for(int i = 0; i < N - 1 ; i++){
        scanf("%d ", &array[i]);
    }
    scanf("%d\n", &array[N-1]);

    long int sum, max = 0, min = 1e9+1;
    int MIN = 0, MAX = 0;
    for(int i = 0; i < N - K + 1; i++){
        sum = 0;
        for( int k = 0; k < K; k++){
            sum = sum + array[i+k];
        }

        if ( sum > max ){
            MAX = i;
            max = sum;
        }
        if ( sum < min ){
            MIN = i;
            min = sum;
        }
    }

    printf("%d %d\n", MIN + 1, MAX + 1);

    return 0;
}