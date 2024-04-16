#include <bits/stdc++.h>
using namespace std;

typedef struct{
    int numerator;
    int denominator;
} fraction;

int main(){
    fraction fractions[] = { 
        {3, 8}, 
        {4, 8}, 
        {2, 8}, 
        {5, 8}, 
        {1, 8}, 
        {6, 8} };
    auto comparator = [&]( fraction a, fraction b ){
        int aux_a = a.numerator * b.denominator,
            aux_b = b.numerator * a.denominator;
        return aux_a < aux_b;
    };
    for( auto &fraction : fractions ){
        printf("%d/%d ", fraction.numerator, fraction.denominator);
    } printf("\n");
    sort(fractions, fractions + 6, comparator);
    for( auto &fraction : fractions ){
        printf("%d/%d ", fraction.numerator, fraction.denominator);
    } printf("\n");

    return 0;
}