#include <stdio.h>


int checkPrime(int num)
{
    int i;
    for(i = 2; i < num; i++){
        if ( num % i == 0){
            return 0;
        }
    }
    
    return 1;
}


int main()
{
    int n, m = 1;
    scanf("%d", &n);

    int i;
    while ( m < 1e3 ){
        if ( !checkPrime(n*m+1) ){
            break;
        }
        m++;
    }

    printf("%d\n", m);

    return 0;
}