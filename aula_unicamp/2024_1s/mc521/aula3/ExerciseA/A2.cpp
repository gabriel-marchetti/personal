#include <bits/stdc++.h>
#define MAX 5010

using namespace std;

int main(){
    int n;
    bool isTriangle = false;
    scanf("%d", &n);
    int array[MAX], visited[MAX]{0};
    int read{0};
    for(int i{0}; i < n; i++){
        scanf("%d", &read);
        read--; //set to array index
        array[i] = read;
    }
    
    int depth{0}, willVisit{0}, current{0};
    for(int i{0}; i < n; i++){
        depth = 1;
        willVisit = array[i];
        visited[i] = 1;
        while( !visited[willVisit] ){
            current = willVisit;
            willVisit = array[willVisit];
            depth++;
            visited[current] = 1;
            if( depth == 3 && willVisit == i ){
                isTriangle = true;
                break;
            }
            if( depth == 3 )
                break;
        }
        if( isTriangle ) break;
        memset(visited, 0, sizeof(visited));
    }

    if( isTriangle )
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}