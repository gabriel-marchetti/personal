#include <stdio.h>
#define error 1e-4


int checkOdd(int n)
{
    // 0:Não impar
    // 1:Impar

    if( n % 2 == 0 ){
        return 0;
    } else {
        return 1;
    }
}


double mySin(double x, double eps)
{
    double value = 0, E, powChain = x, denChain = 1;
    int flag = 1, iter = 1, sgn = 1;
    // Posso modificar
    while ( flag ){
        denChain = denChain / iter;
        powChain = powChain * x * x;
        if ( iter % 2 == 1){
            value = value + powChain/denChain;
        } else {
            value = value - powChain/denChain;
        }
        E       = powChain / (iter + 2);
        if ( E < eps ) break;
        
        iter = iter + 2;
    }

    return value;
}


int main(int argc, char *argv[])
{
    printf("-------O programa das Bolsas-------\n");
    double x;
    printf("Escolha o valor de x entre -1 e 1: "); scanf("%lf", &x);

    // Não atende condições feitas.
    if ( !(x >= -1 && x <= 1) ) return(-1);

    double sin = mySin(x, error);

    printf("Seu valor de seno é: %.2f\n", sin);

    return 0;
}