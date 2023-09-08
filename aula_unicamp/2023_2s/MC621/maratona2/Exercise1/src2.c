#include <stdio.h>

int main()
{
    long int n;
    scanf("%ld", &n);
    long long int sum = 0, actualOdd = 1;

    for (int i = 0; i < n; i++){
        sum = sum + actualOdd;
        actualOdd = actualOdd + 2;
    }

    printf("%lld", sum);

    return 0;
}