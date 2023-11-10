#include <bits/stdc++.h>
#include <cmath>

#define EPS 1e-9
#define PI acos(-1.0)


double dist( point p1, point p2 );

double DEG_to_RAD( double d ){ return d * PI / 180 ;}

/*-----------------------------POINT-----------------------------*/

struct point {
    double x, y;
    point() { x = y = 0.0; }
    point( double _x, double _y ) : x(_x), y(_y) {}

    bool operator < ( point other ) const {
        if( fabs( x - other.x ) > EPS )
            return x < other.x;
        else if( fabs( y - other.y ) > EPS )
            return y < other.y;
        return 0;
    }

    bool operator == ( point other ) const {
        return ( ( fabs(x - other.x) < EPS ) && ( fabs(y - other.y) < EPS) );
    }
};

double dist( point p1, point p2 ){
    /**
     * Return the Euclidian-norm of the vector p1->p2 
     */
    double arg;
    arg = ( p1.x - p2.x ) * ( p1.x - p2.x ) + (p1.y - p2.y) * ( p1.y - p2.y );
    return sqrt(arg);
}

point rotate( point p, double theta ){
    double rad = DEG_to_RAD( theta );
    double COS_THETA = cos(rad), SIN_THETA = sin(rad);
    return point( p.x * COS_THETA - p.y * SIN_THETA,
                  p.x * SIN_THETA + p.y * COS_THETA );
}


/*---------------------------LINES----------------------------*/

struct line{ 
    double a, b, c;
};

bool are_parallel( line l1, line l2 ){
    return( fabs( l1.b - l2.b ) < EPS && fabs( l1.a - l2.a ) < EPS ); 
}

bool are_equal( line l1, line l2 ){
    return ( are_parallel(l1, l2) && fabs(l1.c - l2.c) < EPS );
}

void points_to_line( point p1, point p2, line &l ){
    if( fabs( p1.x - p2.x ) < EPS ){
        l.a = 1.0; l.b = 0.0; l.c = -p1.x;
    } else {
        double dx, dy;
        dx = p2.x - p1.x;
        dy = p2.y - p1.y;
        l.b = 1.0;
        l.a = (-1.0)*( dy/dx );
        l.c = (-1.0)*( l.a * p1.x + p1.y );
    }
}

bool do_intersect( line l1, line l2, point &p ){
    if( are_parallel(l1, l2) ){
        if( fabs(l1.c - l2.c) < EPS ) return true;
        return false;
    } 

    if( l1.a > EPS ){
        p.y = ( l2.a * l1.c + l1.a * l2.c ) / ( l1.a * l2.b - l2.a * l1.b );
        p.x = ( -1.0 ) * ( l1.b * p.y + l1.c ) / l1.a;
    } else {
        p.y = ( -1.0 ) * ( l1.c / l1.b );
        p.x = ( l2.b * l1.c - l1.b*l2.c ) / ( l2.a * l1.b );
    }

    return true;
}