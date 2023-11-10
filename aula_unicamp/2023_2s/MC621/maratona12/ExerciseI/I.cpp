#include <bits/stdc++.h>

using namespace std;
#define EPS 10e-5

struct my_complex{
    double real, complex;    
};

my_complex multiplication( const my_complex &a, const my_complex &b ){
    my_complex result{0};
    result.real = (a.real * b.real) - ( a.complex * b.complex );
    result.complex = ( a.real * b.complex + a.complex * b.real );

    return result;  
}

double complex_norm( const my_complex &a ){
    double result{0};
    result = a.real*a.real + a.complex*a.complex;
    return sqrt(result);
}

my_complex complex_sum( const my_complex &a, const my_complex &b ){
    my_complex result{0};
    result.real = a.real + b.real;
    result.complex = a.complex + b.complex;

    return result;
}

int main(void){
    my_complex actual, past;
    double actual_norm, past_norm;
    int N, iter;
    while( !cin.eof() ){
        actual.real = 0; actual.complex = 0;
        past.real   = 0; past.complex   = 0;
        actual_norm = 0; past_norm = 0;

        cin >> actual.real >> actual.complex >> N;
        for( int i{0}; i < N; i++ ){
            if( fabs( complex_norm(actual) - complex_norm(past) ) < EPS ){

            }
        }    
    }


    return 0;
}