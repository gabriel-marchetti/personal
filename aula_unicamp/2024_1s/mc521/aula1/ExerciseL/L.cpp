#include <bits/stdc++.h>

using namespace std;

int main(){
    int num_of_numbers;
    cin >> num_of_numbers;
    int numbers[num_of_numbers];
    int num_odd{0}, num_even{0}, index{0}, read_number{0};

    for( int i{0}; i < num_of_numbers; i++ ){
        cin >> read_number;
        numbers[i] = read_number;
    }

    for( int i{0}; i < num_of_numbers; i++ ){
        if( numbers[i] % 2 )
            num_odd++;
        else
            num_even++;
    }

    if( num_odd == 1 ){
        for(int i{0}; i < num_of_numbers; i++){
            if( numbers[i] % 2 == 1 )
                index = i;
        }
    } else{
        for(int i{0}; i < num_of_numbers; i++){
            if( numbers[i] % 2 == 0 )
                index = i;
        }
    }

    cout << index + 1 << endl;

    return 0;
}