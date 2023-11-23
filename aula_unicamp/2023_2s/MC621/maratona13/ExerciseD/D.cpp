#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1.0);

int main(void){
    double ax, ay, bx, by,
           M , N, R;

    double dist1, dist2;
    cin >> M >> N >> R >> ax >> ay >> bx >> by;
    dist1 = fabs(ay-by)*R/N + fabs(ax-bx)*PI/M*( min(ay,by) * R / N );
    dist2 = (ay+by)*R/N;
    cout << setprecision(10);
    cout << min(dist1, dist2) << endl;

    return 0;
}