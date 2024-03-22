#include <bits/stdc++.h>
#define MAX 20

int main(){
    int k, array[MAX];
    
    bool skipLine = false;
    while( scanf("%d", &k) ){
        std::fill_n(array, MAX, 0);
        if( k == 0 ) break;
        if( skipLine ) printf("\n");
        for(int i{0}; i < k; i++) scanf("%d", &array[i]);
        
        for(int a{0}; a < k - 5; a++)
            for(int b{a+1}; b < k - 4; b++)
                for(int c{b+1}; c < k - 3; c++)
                    for(int d{c+1}; d < k - 2; d++)
                        for(int e{d+1}; e < k - 1; e++)
                            for(int f{e+1}; f < k; f++)
                                printf("%d %d %d %d %d %d\n",
                                        array[a], array[b], array[c],
                                        array[d], array[e], array[f]
                                      );
        skipLine = true;
    }

    return 0;
}