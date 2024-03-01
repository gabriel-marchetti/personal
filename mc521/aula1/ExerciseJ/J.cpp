#include <bits/stdc++.h>

using namespace std;

int main( ){
    string expression;
    vector<int> numbers;
    getline(cin, expression);

    int number;
    for( int i{0}; i < expression.size(); i = i + 2 ){
        number = (int) expression[i] - 48;
        numbers.push_back( number );
    }

    sort( numbers.begin(), numbers.end() );
    for( int i{0}; i < numbers.size() ; i++ ){
        if( i == numbers.size() - 1 ){
            cout << numbers[i] << endl;
        } else
            cout << numbers[i] << '+';
    }

    return 0;
}