#include <SDL2/SDL.h>
#include <iostream>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int main(int argc, char *argv[])
{
    // Variables

    SDL_Window *window;
    SDL_Event event;
    SDL_Surface *spriteMario = NULL;
    bool end = false;


    // Window

    window = SDL_CreateWindow("My Mario", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

    if(!window)
    {
        std::cout << "SDL Error : " << SDL_GetError() << std::endl;
        return -1;
    }

    // Event loop

    while(!end)
    {
        SDL_WaitEvent(&event);

        if(event.window.event == SDL_WINDOWEVENT_CLOSE)
            end = true;


        //surfaces loading
        spriteMario=SDL_LoadBMP("sprite/mario/spritemario.bmp");

        if (spriteMario){
            int frameRate = 100;
            int spriteWidth = 64;
            int spriteHeight = 98;
            int startposition = 140;
            int cmpt = 0;

            while (cmpt < 4){
                //blit sprite
                SDL_Rect dest = { 10,10,0,0 };
                SDL_Rect srcrect = {startposition,0,spriteWidth,spriteHeight};
                SDL_BlitSurface (spriteMario,&srcrect,SDL_GetWindowSurface(window),&dest);

                SDL_UpdateWindowSurface(window);
                SDL_Delay(frameRate);

                cmpt++;
                startposition += spriteWidth;

            }

            SDL_FreeSurface(spriteMario);

        }else{
            std::cout << "SDL Error : " << SDL_GetError() << std::endl;
            return -1;
        }
    }


    return 0;
}
