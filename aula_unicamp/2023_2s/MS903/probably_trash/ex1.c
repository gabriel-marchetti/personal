#include <stdio.h>
#include <math.h>

#define pi 3.14159265359

int checkTriangularity(double a, double b, double c)
{
    // 0: não triângulo.
    // 1: triângulo.
    // Verificar desig. Triangular para a,b e c.
    int flag = 0;
    if ( a < b + c && b < a + c && c < a + b){
        flag = 1;
    } 
    return flag;
}


double absoluteVal(double val)
{
    if ( val < 0 ){
        return -val;
    } else {
        return val;
    }
}


double mysqrt(double x, double error)
{
    double xAnt, xAct;
    xAct = x/2; xAnt = 0;
    while ( absoluteVal(xAct - xAnt) > error ){
        xAnt = xAct;
        xAct = 0.5*(xAct + x/xAct);
    }

    return xAct;
}


double computeArea(double a, double b, double c)
{
    // Apply Heron's formula:
    // A = sqrt(s*(s-a)*(s-b)*(s-c)) 
    // where s denotes the semi-perimeter
    double error = 1e-6;
    double sP = (a + b + c) / 2;
    double area = mysqrt(sP*(sP-a)*(sP-b)*(sP-c), error);

    return area;
}

double computeCosInv(double a, double b, double c)
{
    double value = (c*c + b*b - a*a) / (2 * b * c);
    return acos(value);
}


double computePerimeter(double a, double b, double c)
{
    return (a + b + c);
}


int main(int argc, char *argv[])
{
    // # Entrada: a, b,c 
    // # Saída:     "Não podem ser componentes de lados de um triângulo" ou
    //              "São as componentes dos lados de um triângulo com área __, perímetro __ e ângulos internos __ , __ e __."

    double a,b,c;
    scanf("%lf %lf %lf", &a, &b, &c);

    if ( a < 0 && a == 0 && b < 0 && b == 0 && c < 0 & c == 0){
        puts("Não podem ser os comprimento de lado de um triângulo.");
        return(-1);
    }
    // a, b, c parecem ser válidos.
    int cond = checkTriangularity(a, b, c);
    if ( cond ){
        double area = computeArea(a, b, c);
        double perimeter = computePerimeter(a, b, c);
        double angle1 = computeCosInv(a, b, c);
        double angle2 = computeCosInv(b, c, a);
        double angle3 = computeCosInv(c, a, b);
        // Converting to graus:
        angle1 = (180 * angle1)/pi;
        angle2 = (180 * angle2)/pi;
        angle3 = (180 * angle3)/pi;

        printf("São as componentes dos lados de um triângulo com área %.2f, perímetro %.2f e ângulos internos %.2f, %.2f e %.2f\n", area, perimeter,
                angle1, angle2, angle3);
    } else {
        puts("Não podem ser os comprimento de lado de um triângulo.");
        return(-1);
    }
}