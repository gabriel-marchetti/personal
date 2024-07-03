#include <stdio.h>
#include <math.h>

int main(){
    double pi = M_PI;
    int digits;
    scanf("%d", &digits);
    printf("%.*f\n", digits, pi);
}