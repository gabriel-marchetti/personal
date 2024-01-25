#include <bits/stdc++.h>

using namespace std;

void printMaze(const vector<vector<char>> &labirinto ){
    for(const auto &row : labirinto){
        for(const char &ch : row ){
            cout << ch;
        }
        cout << '\n';
    }
}

void mazeResolve( long long currentRow, long long currentCol, long long maxRow, long long maxCol,
                 vector<vector<char>> &labirinto, long long &contador
            ){
                    if( currentRow > maxRow || currentCol > maxCol ||
                        currentRow < 0 || currentCol < 0
                    ) return;

                    if( labirinto[currentRow][currentCol] == 'X' || 
                        labirinto[currentRow][currentCol] == '*' ||
                        labirinto[currentRow][currentCol] == 'o'
                    ) return;

                    labirinto[currentRow][currentCol] = 'o';

                    //printMaze(labirinto);
                    //cout << "----------------------" << '\n';

                    long long above = currentRow - 1,
                        below = currentRow + 1,
                        lefty = currentCol - 1,
                        righty = currentCol + 1;
                    int numOfAsterisks{0};

                    if( below <= maxRow && labirinto[below][currentCol] == '*' )
                        numOfAsterisks++;
                    if( above >= 0 && labirinto[above][currentCol] == '*' )
                        numOfAsterisks++;
                    if( lefty >= 0 && labirinto[currentRow][lefty] == '*' )
                        numOfAsterisks++;
                    if( righty <= maxCol && labirinto[currentRow][righty] == '*' )
                        numOfAsterisks++;

                    //cout << numOfAsterisks << endl;
                    contador += numOfAsterisks;
                    numOfAsterisks = 0;
                    mazeResolve( below, currentCol, maxRow, maxCol, labirinto, contador );
                    mazeResolve( above, currentCol, maxRow, maxCol, labirinto, contador );
                    mazeResolve( currentRow, lefty, maxRow, maxCol, labirinto, contador );
                    mazeResolve( currentRow, righty, maxRow, maxCol, labirinto, contador );

}

int main( ){
    long long sizeLines, sizeColumns, hotSpots;
    cin >> sizeLines >> sizeColumns >> hotSpots;
    cin.ignore();
    vector<vector<char>> labirinto(sizeLines, vector<char>(sizeColumns));

    for( int i = 0; i < sizeLines; i++ ){
        for( int j = 0; j < sizeColumns; j++ ){
            cin >> labirinto[i][j];
        }
    }


    long long row, col, contador{0};
    // cout << hotSpots << '\n';
    for(int i = 0; i < hotSpots; i++ ){
        cin >> row >> col;
        contador = 0;
        mazeResolve( row - 1, col - 1, sizeLines - 1, sizeColumns - 1, labirinto, contador);
        cout << contador << '\n';
    }

    /*
    for(const auto &row : labirinto){
        for(const char &ch : row ){
            cout << ch;
        }
        cout << '\n';
    }
    */

   

    return 0;
}