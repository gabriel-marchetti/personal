#include <iostream>
#include <unistd.h>

int main(){
    char chars[] = {'o', 'O'};

    for( int i{0}; i < 15; i++ ){
        for( int j{0} ; j < i; j++ ){
            printf(" ");
        }
        printf("%c\r", chars[ i % sizeof(chars) ] );
        fflush(stdout);
        usleep(200000);
    }

    return 0;
}