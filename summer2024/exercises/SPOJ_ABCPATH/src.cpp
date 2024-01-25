#include <bits/stdc++.h>

const int MAXN = 51;

char uppercaseAlphabet[26];
int H, W, initialH, initialW, length;
char path[MAXN][MAXN],
     reading{0};

int list1[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int list2[8] = {1, 1, 0, -1, -1, -1, 0, 1};

struct pair{
    int posH, posW;
};

void printPath( int H, int W ){
    for( int i{0}; i < H; i++ ){
        for( int j{0}; j < W; j++ ){
            std::cout << path[i][j];
        }
        std::cout << '\n';
    }
}

void dfs( int currentH, int currentW, int actualLetter ){
    if( currentH < 0 || currentH >= H ||
        currentW < 0 || currentW >= W
    ) return;
    
    // printf("Estou em (%d, %d)\n", currentH, currentW);

    for( int i{0}; i < 8; i++ ){
        int checkPositionH = currentH + list1[i],
            checkPositionW = currentW + list2[i];
        if( path[checkPositionH][checkPositionW] == uppercaseAlphabet[actualLetter + 1] ){
            if( length < (actualLetter+1) )
                length = actualLetter + 1;
            dfs( checkPositionH, checkPositionW, actualLetter + 1 );
        }
    }

}

int main( ){
    int testCase{1};

    do{
        length = 0;
        int maxLength{0};
        std::cin >> H >> W;
        if( H == 0 )
            break;
        
        for( int i{0}; i < 26; i++ ){
            uppercaseAlphabet[i] = 'A' + i;
        }

        // Need to store all A's and check tha maximum one!
        pair listOfAs[MAXN];
        int numOfStartingPositions{0};

        for( int i{0}; i < H; i++ ){
            for( int j{0}; j < W; j++ ){
                std::cin >> reading;
                path[i][j] = reading;
                if( reading == 'A' ){
                    listOfAs[numOfStartingPositions].posH = i;
                    listOfAs[numOfStartingPositions].posW = j;
                    numOfStartingPositions++;
                }
            }
            std::cin.ignore();
        }

        for( int i{0}; i < numOfStartingPositions; i++ ){
            length = 0;
            dfs( listOfAs[i].posH, listOfAs[i].posW, 0 );
            if( maxLength < length )
                maxLength = length;
        }

        // It is printing correctly!
        // printPath(H, W);

        std::cout << "Case " << testCase << ": " << maxLength + 1 << '\n';
        testCase++;
    } while ( true );

}