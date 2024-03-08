#include <bits/stdc++.h>

using namespace std;

int main(  ){
    int rows, cols;
    cin >> rows >> cols;

    int discriminant;
    for( int rows_aux{0}; rows_aux < rows; rows_aux++ ){
        if( rows_aux % 2 ){
            discriminant = (rows_aux - 1) / 2;
            if( discriminant % 2 ){
                cout << '#';
                for( int i{0}; i < cols - 1; i++ )
                    cout << '.';
            } else{
                for( int i{0}; i < cols - 1; i++ )
                    cout << '.';
                cout << '#';
            }
        } else {
            for( int cols_aux{0}; cols_aux < cols; cols_aux++)
                cout << '#';
        }

        cout << endl;
    }

}