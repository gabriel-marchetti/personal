#include <stdio.h>

long int **createMatrix(int lin, int col)
{
    long int **matriz = (long int **)calloc(lin, sizeof(long int *));
    for(int i = 0; i < lin; i++){
        matriz[i] = (long int *)calloc(col, sizeof(long int));
    }

    return matriz;
}

int main()
{
    int numIntervals;
    scanf("%d ", &numIntervals);

    int **matriz = createMatrix(numIntervals, 2);
    int i;
    for (i=0; i < numIntervals; i++){
        scanf("%d %d ", &(matriz[i][0]), &(matriz[i][1]));
    }
    
}