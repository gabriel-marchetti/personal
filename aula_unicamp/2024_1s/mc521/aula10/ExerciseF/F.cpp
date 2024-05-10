#include <bits/stdc++.h>
using namespace std;

char chessboard[8][8];

typedef struct point{
    int r, c;
};

int rookMove( point start, point finish ){
    if( start.c == finish.c && start.r == finish.r )
        return 0;
    if( start.c == finish.c || start.r == finish.r )
        return 1;
    else
        return 2;
}

void kingMove( point position ){
    if( position.c > 8 || position.r > 8 ) return;
    if( position.c < 0 || position.r < 0 ) return;
}



int main(){
    point start, finish;
    cin >> start.r >> start.c >> finish.r >> finish.c;


    return 0;
}