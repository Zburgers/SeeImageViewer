#include<stdio.h>
#include<stdlib.h>
#include<SDL2/SDL.h>

int main()
{

    printf("hello world, window runs\n");

    const int width = 800;
    const int height = 600;

    SDL_Window *pwindow = SDL_CreateWindow("Image viewer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED , width, height, SDL_WINDOW_ALWAYS_ON_TOP);
    SDL_Surface *psurface =  SDL_GetWindowSurface(pwindow);

    Uint8 r = 0x00;
    Uint8 g = 0xAD;
    Uint8 b = 0xD8;
    Uint8 a = 0xE6;

    // 0x00ADD8E6

    Uint32 pixelvalue = SDL_MapRGBA(psurface->format,r,g,b,a);
    SDL_Rect pixel = (SDL_Rect){0,0,1,1};
    for (int x = 0; x<100; x++)
    {
        for(int y = 0; y<200; y++)
        {
            pixel.x = x;
            pixel.y = y;
            SDL_FillRect(psurface, &pixel, pixelvalue);
        }
    }

    SDL_UpdateWindowSurface(pwindow);
    
    SDL_Delay(3000);
}