#include <bits/stdc++.h>

struct Restriction{
    int S_0, S_1, c;
};

int testThisCase( int n, int m, const int position[], 
                  const Restriction restrictions[] ){
    for( int i{0}; i < m; i++ ){
        int index1 = restrictions[i].S_0, index2 = restrictions[i].S_1;
        if( restrictions[i].c < 0 ){
            /**
             * If we are in the case that c < 0, we want to answer the question
             * does S_0 and S_1 are at least c seats between each other. 
             * If they do, then it's a sucessuful restriction, but we want to
             * check the other restriction, so we negate this case and consider
             * a failed situation.
             */
            if( !( abs(position[index1] - position[index2]) >= abs(restrictions[i].c) ) )
                return 0;
        } else{
            /**
             * Same as above but for the case c > 0, which we want to know if
             * S_0 and S_1 are at most c seats between each other. 
             */
            if( !( abs(position[index1] - position[index2]) <= abs(restrictions[i].c) ) )
                return 0;
        }
    }

    /** 
     * If all restriction are not failed we consider it a sucess! 
     */
    return 1;
}

int main(){
    int sucessufulSituation{0}, n{0}, m{0}, a{0}, b{0}, c{0},
        position[8];
    Restriction restrictions[20];

    while( true ){
        std::cin >> n >> m;

        if( n == 0 && m == 0 ) break;
        // Cleaning variables.
        sucessufulSituation = 0;
        for(int i{0}; i < 8; i++)
            position[i] = i;
        for(int i{0}; i < m; i++){
            std::cin >> a >> b >> c;
            restrictions[i].S_0 = a;
            restrictions[i].S_1 = b;
            restrictions[i].c = c;
        }

        do{
            sucessufulSituation += testThisCase( n, m, position, restrictions );
        } while( std::next_permutation( position, position + n) );
    
        printf("%d\n", sucessufulSituation);
    }

    return 0;
}