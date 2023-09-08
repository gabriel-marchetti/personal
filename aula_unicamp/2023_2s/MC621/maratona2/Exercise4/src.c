#include <stdio.h>
#include <stdlib.h>

char **criaMatrix(int lin, int col)
{
    char **matrix = (char **)calloc(lin, sizeof(char *));
    for(int i = 0; i < lin; i++){
        matrix[i] = (char *)calloc(col, sizeof(char));
    }

    return matrix;
}

int main()
{
    int N, M;
    scanf("%d %d\n", &N, &M);

    int tecnoX = 0,     tecnoY = 0;
    int enemy1X = 0,    enemy1Y = 0;
    int enemy2X = 0,    enemy2Y = 0;
    int flag = 0; 
    char **matrix = criaMatrix(N, M), lixo;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf("%c", &matrix[i][j]);
            if(matrix[i][j] == 'T'){
                tecnoX = i;
                tecnoY = j;
            }
            if(matrix[i][j] == '*' && flag == 0){
                enemy1X = i;
                enemy1Y = j;
                flag    = 1;
            }
            if(matrix[i][j] == "*" && flag == 1){
                enemy2X = i;
                enemy2Y = j;
            }
        }
        scanf("%c", &lixo);
    }

    int neededBlocks    = 0;
    int searching       = 1;
    while ( searching )

    return 0;
}