#include <bits/stdc++.h>

int main(){
    int N;

    std::bitset<10> alreadyUsed, mustBe;
    std::vector<int> abcde_store, fghij_store;
    int fghij_copy, abcde_copy, tmp;
    mustBe.set();

    while( true ){
        scanf("%d", &N);
        if( N == 0 ) break;
        abcde_store.clear(); fghij_store.clear();
        for(int fghij{1234}; fghij <= 98765 / N; fghij++){
            alreadyUsed.reset();
            fghij_copy = fghij;
            abcde_copy = N * fghij_copy;
            if( abcde_copy >= 100000 ) break;

            while( abcde_copy ){ 
                tmp = abcde_copy % 10;
                abcde_copy = abcde_copy / 10;
                alreadyUsed.set(tmp);
            }

            while( fghij_copy ){ 
                tmp = fghij_copy % 10;
                fghij_copy = fghij_copy / 10;
                alreadyUsed.set(tmp);
            }
            
            // 0-index first digit
            if( fghij <= 9999 ) alreadyUsed.set(0);
            if( N * fghij <= 9999 ) alreadyUsed.set(0);

            if( alreadyUsed == mustBe ){
                abcde_store.push_back( fghij * N );
                fghij_store.push_back( fghij );
            }
        }

        if( abcde_store.empty() )
            printf("There are no solutions for %d.\n", N);
        else{
            for( std::vector<int>::iterator it_abcde = abcde_store.begin(),
                 it_fghij = fghij_store.begin(); 
                 it_abcde != abcde_store.end(); it_abcde++, it_fghij++)
            {
                printf("%05d / %05d = %d\n", *it_abcde, *it_fghij , N);
            }
        }
        
    }

    return 0;
}