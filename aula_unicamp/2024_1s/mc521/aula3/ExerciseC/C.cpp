#include <bits/stdc++.h>
#define MAX 210

using namespace std;

int howMany( int (&array)[MAX], int start ){
    int counter{0};
    int current{start};
    do{
        current = array[current];
        counter++;
    }while ( current != start );
    return counter;
}

int main(){
    int q, n, array[MAX], read;
    scanf("%d", &q);
    while(q--){
        scanf("%d", &n);
        for(int i{0}; i < n; i++){
            scanf("%d", &read);
            read--;
            array[i] = read;
        }
        for(int i{0}; i < n; i++)
            printf("%d ", howMany(array, i));
        printf("\n");
    }

    return 0;
}