#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    char vowels[] = {'a', 'e', 'i', 'o', 'u', 'y'};
    char string[100], aux;
    int flag;
    cin >> string;
    for(int i{0}; string[i] != '\0'; i++){
        aux = string[i];
        flag = 1;
        if( aux < 97 ){
            aux += 32;
        }
        for(int j{0}; j < 6; j++){
            if( aux == vowels[j] ){
                flag = 0;
            }
        }

        if (flag) printf(".%c", aux);
    }
    cout << endl;

    return 0;
}