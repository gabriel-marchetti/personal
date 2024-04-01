#include <iostream>
#include "solution.cpp"

using namespace std;

void printSolution( vector<int> &solution ){
    bool isLast = false;
    int offset = 0;
    cout << '[';
    for( auto x : solution ){
        isLast = ( solution.begin() + offset == solution.end() - 1 );
        offset++;
        if( isLast )
            cout << x;
        else 
            cout << x << ',';
    }
    cout << ']' << endl;
}

int main(){
    Solution sol;

    vector<int> test = vector<int>( {2, 7, 11, 15} ),
                solution = vector<int>();
    int target = 9;
    
    
    solution = sol.twoSum( test, target );
    printSolution( solution );
    test.clear(); solution.clear();

    test = vector<int>( {3, 2, 4} );
    target = 6;
    solution = sol.twoSum( test, target );
    printSolution( solution );
    test.clear(); solution.clear();

    test = vector<int>( {3, 3} );
    target = 6;
    solution = sol.twoSum( test, target );
    printSolution( solution );
    test.clear(); solution.clear();
    

    return 0;
}