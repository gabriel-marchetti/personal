#include <bits/stdc++.h>
#define EPS 10e-5
#define MAXITER 50

using namespace std;

class Equation{
    private:
        double p, q, r, s, t, u;
    public:
        Equation(){
            this->p = 0.0;
            this->q = 0.0;
            this->r = 0.0;
            this->s = 0.0;
            this->t = 0.0;
            this->u = 0.0;
        }
        
        void setParameters( double p, double q, double r, double s, double t, double u ){
            this->p = p;
            this->q = q;
            this->r = r;
            this->s = s;
            this->t = t;
            this->u = u;
        }

        double compute( double x ){
            return p * exp( -1.0 * x ) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
        }
};

double bissection( double a, double b, Equation eq){
    double c{0}, result{0};

    for( int i{0}; i < MAXITER; i++ ){
        c = ( a + b ) / 2.0 ;
        result = eq.compute( c );
        if( signbit(result) == signbit(eq.compute(b)) ){
            b = c;
        }
        else{
            a = c;
        }
    }
    return c;
}

int main(){
    double p, q, r, s, t, u,
           result, value_a, value_b;
    Equation eq = Equation();
    while( cin >> p >> q >> r >> s >> t >> u ){
        //cout << p << ' ' << q << ' ' << r << ' ' << s << ' ' << t << ' ' << u << ' ' << '\n';
        eq.setParameters(p, q, r, s, t, u);
        value_a = eq.compute(0.0); value_b = eq.compute(1.0);
        result = bissection(0.0, 1.0, eq);
        if( signbit(value_a) == signbit(value_b) ){
            cout << "No solution" << '\n';
        }
        else{
            printf("%.4f\n", result);
        }
    }

    return 0;
}