#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
bool is_running = false;

bool initialize_window(void)
{
    if ( SDL_Init(SDL_INIT_EVERYTHING) ){
        fprintf(stderr, "Error Initializing SDL.\n");
        return false;
    }
    // [X]To do: Create SDL Window.
    window = SDL_CreateWindow(
        NULL,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SDL_WINDOW_BORDERLESS
    );
    if ( window == NULL ){
        fprintf(stderr, "Could't initialize SDL window.\n");
        return false;
    }

    // []To do: Create a SDL renderer.

    renderer = SDL_CreateRenderer(
        window,
        -1,
        0
    );
    if ( renderer == NULL ){
        fprintf(stderr, "Could't initialize SDL renderer.\n");
        return false;
    }

    return true;
}

int main(void)
{
    /*
     * []TO DO: Create a SDL Window.
     */
    is_running = initialize_window();
    if( !is_running ){
        printf("Could't initialize the window.\n");
    }

    return 0;
}