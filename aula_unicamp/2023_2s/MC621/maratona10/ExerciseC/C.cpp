#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, M;
    // N: number of word in the dictionary
    // M: number of plates
    cin >> N >> M;
    string dict[5000];
    for(int i{0}; i < N; i++){
        cin >> dict[i];
    }

    bool aux1 = false, aux2 = false, aux3 = false;
    string plate;
    for(int i{0}; i < M; i++){
        cin >> plate;
        transform(plate.begin(), plate.end(), plate.begin(), ::tolower);
        // cout << plate << endl;
        for(int j{0}; j < N; j++){
            aux1 = aux2 = aux3 = false;
            for(int k{0}; k < dict[j].size(); k++){
                // printf("%c", dict[j][k]);
                if( aux2 && plate[2] == dict[j][k] ){ 
                    aux3 = true;
                    break;
                } 
                else if( aux1 && plate[1] == dict[j][k] ) aux2 = true;
                else if( plate[0] == dict[j][k] ) aux1 = true;
            }
            // printf("\n");
            if( aux3 ){
                cout << dict[j] << endl;
                break;
            }
        }
        if( !aux3 ) cout << "No valid word" << endl;
    }

    return 0;
}