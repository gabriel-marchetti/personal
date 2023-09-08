#include <stdio.h>

int main()
{
    int n;
    char string[4];
    scanf("%d\n", &n);
    for(int i = 0; i < n; i++){
        scanf("%s", string);
        if( string[0] == 'y' || string[0] == 'Y'){
            if ( string[1] == 'e' || string[1] == 'E'){
                if ( string[2] == 's' || string[2] == 'S'){
                    printf("YES\n");
                } else {
                    printf("NO\n");
                }
            } else {
                printf("NO\n");
            }
        } else {
            printf("NO\n");
        }
    }

    return 0;
}