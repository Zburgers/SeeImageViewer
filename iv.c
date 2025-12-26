#include<stdio.h>
#include<stdlib.h>
#include<SDL2/SDL.h>

int main()
{

    printf("hello world, window runs\n");
    // Start here 

    FILE *in = stdin;
    char *pthrow = calloc(1000, sizeof(char));
    
    // Read first line specifier p3/p6 - ignore
    fgets(pthrow, 1000, in);
    
    // Read second line - Comment
    fgets(pthrow, 1000, in);


    //Read third line: width/height
    char *pdimensions = calloc(1000, sizeof(char));
    fgets(pdimensions, 1000, in);
    
    //Read fourth line 255 - ignore
    fgets(pthrow, 1000, in);
    free(pthrow);

    int width = -1;
    int height = -1;

    sscanf(pdimensions, "%d %d\n", &width, &height);
    free(pdimensions);
    printf("width= %d, height= %d\n", width, height);

    SDL_Window *pwindow = SDL_CreateWindow("Image viewer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED , width, height, SDL_WINDOW_ALWAYS_ON_TOP);
    SDL_Surface *psurface =  SDL_GetWindowSurface(pwindow);

    // 0x00ADD8E6
    //Uint8 r = 0x00;
    //Uint8 g = 0xAD;
    //Uint8 b = 0xD8;
    //Uint8 a = 0xE6;
    // Uint32 pixelvalue = SDL_MapRGBA(psurface->format,r,g,b,a);

    // Parsing Image Binary Data

    
    SDL_Rect pixel = (SDL_Rect){0,0,1,1};
    Uint32 color = 0;
    for (int y = 0; y<width; y++)
    {
        for(int x = 0; x<height; x++)
        {
            Uint8 r,g,b;
            r = (char) getchar();
            g = (char) getchar();
            b = (char) getchar();
            color = SDL_MapRGB(psurface->format,r,g,b);

            pixel.x = x;
            pixel.y = y;
            SDL_FillRect(psurface, &pixel, color);
        }
    }

    SDL_UpdateWindowSurface(pwindow);
    
    // SDL_Delay(3000);
    int app_running = 1;
    while (app_running)
    {

        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                app_running = 0;
            }
        }
        SDL_Delay(10);
    }
}