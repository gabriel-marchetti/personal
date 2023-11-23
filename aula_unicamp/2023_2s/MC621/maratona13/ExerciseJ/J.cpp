#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1.0);

int main(void){
    char ABC[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 
           'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
           'W', 'X', 'Y', 'Z'};
    int num_of_holes{0};
    cin >> num_of_holes;
    double holes[num_of_holes];
    for(int i{0}; i < num_of_holes; i++){
        cin >> holes[i];
    }

    double radius;
    double areas[num_of_holes];
    for(int i{0}; i < num_of_holes; i++){
        radius = holes[i];
        areas[i] = PI*radius*radius;
    }

    double a, b, c;
    int num_of_pegs;
    cin >> num_of_pegs;
    for(int i{0}; i < num_of_pegs; i++){
        cin >> a >> b >> c;
    }


    return 0;
}