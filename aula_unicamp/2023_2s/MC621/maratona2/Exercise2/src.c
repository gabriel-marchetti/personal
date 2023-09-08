#include <stdio.h>

int main()
{
    int x1, x2, y1, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    int days = 0;
    if( x1 <= x2 && y1 <= y2 ){
        printf("-1\n");
    } else {
        if ( x1 > x2 ){
            printf("0\n");
        } else {
            // x1 menor ou igual que x2, agora precisamos avaliar is casos a parte.
            while ( x1 <= x2 ){
                x1 = x1 + y1;
                x2 = x2 + y2;
                days++;
            }
            printf("%d\n", days);
        }
    }

    return 0;
}