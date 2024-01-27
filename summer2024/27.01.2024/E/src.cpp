#include <bits/stdc++.h>

bool checkIfPossible( const std::vector<int> &vect ){
    int sum{0};
    for( int it{0}; it < vect.size(); it++ ){
        sum += vect[it];
    }

    sum -= 12;
    return ( 0 <= sum ) && ( sum <= 6 );
}

int main( ){
    int testCases{0};
    std::cin >> testCases;

    int n{0}, order{1};
    std::vector<int> scoreboard;
    while(testCases--){
        n = 0;
        scoreboard.clear();
        for( int it{0}, read{0}; it < 4; it++ ){
            std::cin >> read;
            scoreboard.push_back(read);
        }

        if( !checkIfPossible(scoreboard) ){
            std::cout << "Case #" << order << ": " << "Wrong Scoreboard\n";
        } else if( scoreboard[0] == 0 ){
            if( scoreboard[1] == 6 && scoreboard[2] == 6 && scoreboard[3] == 6 )
                std::cout << "Case #" << order << ": " << "No\n";
            else
               std::cout << "Case #" << order << ": " << "Yes\n";
        } else if( scoreboard[0] == 9 ){
            if( scoreboard[1] == 3 && scoreboard[2] == 3 && scoreboard[3] == 3 )
                std::cout << "Case #" << order << ": " << "No\n";
            else
                std::cout << "Case #" << order << ": " << "Yes\n"; 
        } else {
            std::cout << "Case #" << order << ": " << "No\n";
        }  
        order++;
    }

    return 0;
}