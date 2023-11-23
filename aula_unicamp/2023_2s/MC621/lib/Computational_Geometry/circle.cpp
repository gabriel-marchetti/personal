#include <bits/stdc++.h>

#define EPS 1e-9
#define PI acos(-1.0)

using namespace std;

double DEG_to_RAD( double d ){ return d * PI / 180 ;}

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

int insideCircle( point p, point c, double r ){
    /*
     * If point is in the border: return 0;
     * If point is in the interior: return -1;
     * If point is in the exterior: return 1;
    */ 
    double dx = p.x - c.x, dy = p.y - c.y;
    double region = dx * dx + dy * dy - r * r;

    if( -EPS <= region <= EPS ){
        return 0;
    } else if( region < -EPS ){
        return -1;
    } else{
        return 1;
    }
}

double circunferencePerimeter( double radius ){ return 2*PI*radius; }

double chordLength( double radius, double alpha ){
    /*
     * Return the length of the chord;
     * alpha must be on RADIANS
    */
    double chord = radius * sqrt( 2 * ( 1 - cos(alpha) ) );
    return chord;
}

double sectorLength( double radius, double alpha ){
    // Alpha must be on RADIANS
    return radius * alpha;
}

double sectorArea( double radius, double alpha ){
    // Alpha must be on RADIANS;
    return ( alpha * radius * radius ) / 2;
}

double chordArea( double radius, double alpha ){
    // Alpha must be on RADIANS.
    /*
     * This name is pretty bad, but i could´t figure another one.
    */

    return radius * radius * ( alpha / 2 - sin( alpha ) );
}


void twoPointsAndRadius( double radius, point A, point B, point &sol1, point &sol2 ){
    /*
     * Problem: Given two points and a radius of a circunference. Define
     * the center of the two circunferences that contains the points and
     * has radius r.
    */
    double dx = A.x - B.x, dy = A.y - B.y;
    point aux;
    aux.x = dx / 2;
    aux.y = dy / 2;
    // Norm of CA
    double EuclNorm = sqrt(dx*dx + dy*dy);
    double scale = sqrt( radius*radius - EuclNorm * EuclNorm );
    aux.x = aux.x * scale / EuclNorm;
    aux.y = aux.y * scale / EuclNorm;

    sol1.x = aux.y;
    sol1.y = -aux.x;
    sol2.x = -aux.y;
    sol2.y = aux.x;
}

double lengthPoint2Point( point A, point B ){
    double dx = A.x - B.y, dy = A.y - B.y;
    return sqrt(dx*dx + dy*dy);
}

double areaTriangle( point A, point B, point C, double s ){
    double aux1 = lengthPoint2Point(A, B),
           aux2 = lengthPoint2Point(B, C),
           aux3 = lengthPoint2Point(C, A);
    return sqrt( s * ( s - aux1 ) * ( s - aux2 ) * ( s - aux3 ) );
}

void areaTriangle( point A, point B, point C, point &center, double &radius ){
    double semiPerimeter = lengthPoint2Point(A, B) + lengthPoint2Point(B, C) + lengthPoint2Point(C, A);
    semiPerimeter = semiPerimeter / 2;
    double area = areaTriangle( A, B, C, semiPerimeter );

    if( fabs(semiPerimeter) < EPS || fabs(area) < EPS ){
        printf("There is no such circle.\n");
        return;
    }
    radius = area / semiPerimeter;

    double a1 = C.y - A.y,
           b1 = A.x - C.x,
           c1 = -a1*A.x - b1*A.y,
           a2 = B.y + (-A.y + C.y) / 2,
           b2 = -B.x + ( A.x - C.y ) / 2,
           c2 = -a2*B.x - b2*B.y;
    
    /*
     * There is a problem on this code, if the lines 
     * a1*x + b1*x + c1 = 0
     * a2*x + b2*x + c2 = 0
     * Then there might be an ERROR.
    */
    center.y = (a2*c1 - c2*a1) / (b2*a1 - b1*a2);
    center.x = (-b1*center.y - c1) / a1;
}

void circumscribedCircle( point A, point B, point C, point &centerCircle, double &r ){

}