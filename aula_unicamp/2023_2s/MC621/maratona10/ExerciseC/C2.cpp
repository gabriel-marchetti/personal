#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> dict(N);
    
    for (int i = 0; i < N; i++) {
        cin >> dict[i];
    }

    for (int i = 0; i < M; i++) {
        string plate;
        cin >> plate;
        transform(plate.begin(), plate.end(), plate.begin(), ::tolower);
        
        bool found = false;
        for (const string& word : dict) {
            bool aux1 = false, aux2 = false, aux3 = false;
            for (char c : word) {
                if (aux2 && plate[2] == c) {
                    aux3 = true;
                    break;
                } else if (aux1 && plate[1] == c) {
                    aux2 = true;
                } else if (plate[0] == c) {
                    aux1 = true;
                }
            }
            
            if (aux3) {
                cout << word << endl;
                found = true;
                break;
            }
        }
        
        if (!found) {
            cout << "No valid word" << endl;
        }
    }

    return 0;
}
