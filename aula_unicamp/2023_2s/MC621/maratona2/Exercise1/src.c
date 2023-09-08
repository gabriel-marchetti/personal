#include <stdio.h>
#include <math.h>

long int integerPart(long int n)
{
    long int value = n / 2;
    return value + 1;
}

long int sum(long int n)
{
    long int value = (2*n)*integerPart(2*n-1)/2;
    return ( value );
}

int main()
{
    long int n;
    scanf("%ld", &n);

    n = sum(n);

    printf("%ld\n", n);
    return 0;
}