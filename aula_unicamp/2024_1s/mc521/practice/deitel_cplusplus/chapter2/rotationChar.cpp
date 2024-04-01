#include <iostream>
#include <unistd.h>

int main(){
    char chars[] = { '-', '\\', '|', '/' };

    for( int i{0}; ; i++ ){
        printf("%c\r", chars[ i % sizeof(chars) ]);
        fflush(stdout);
        usleep(200000);
    }

    return 0;
}